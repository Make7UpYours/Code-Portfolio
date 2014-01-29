##CS 101
##Program 6
##William Freeman
##wjfkc2@mail.umkc.edu
##
##PROBLEM:
##    Create an evil hang-man game that uses dictionaries and groups words into
##     various word families based upon user input. Program will always choose
##     the largest word family until only a single word remains or the user runs
##     out of guesses.
##
##ALGORITHM:
##    1. Read through the scrabble dictionary file, organizing each word within
##        the file into a dictionary where the keys are word lengths and the
##        values are sets of words paired with the specific lengths.
##    2. Assign a variable to an alphabetical set consisting of all letters of the
##        alphabet.
##    3. Initalize an empty set to keep track of the letters that the user will choose.
##    4. Prompt the user for a desired word length.
##        a. Ensure the user enters a valid words length that is a key value within
##            the word dictionary.
##    5. Prompt the user for a number of guesses they would like to have during
##        the game.
##        a. Ensure that the user enters a digit and that the digit is >0.
##        b. Assign the digit to a guess_limit variable.
##    6. Initalize a game_state variable that will consist of "-"*user_word_length.
##    7. Create a word_set consisting of all the possible words that are in use
##        based upon the user's specified length.
##    8. Prompt the user to select a letter from the alpha_set.
##        a. If the user does not pick a letter that is currentally in the alpha_set
##            then reprompt until they do.
##        b. Once a valid choice is made by the user, remove the letter from the
##            alpha_set and add the letter to the user_choice_set.
##    9. Organize each word in word_set into a word_family dictionary based upon
##        where the letter chosen by the user falls within specific words.
##        (keys will be the game_state stored as a str and the values will consist of
##        specific words paired with the game_state)
##        a. Select the largest grouping of words and assign that group of words to
##            word_set.
##        b. Update the game_state if needed depending upon which word family
##            was chosen.
##    10. Subtrack 1 from the guess_limit if the game_state remains the same
##          after step 9b.
##    11. Display the current game_state along with other useful infromation to
##          the user.
##    12. Continue to repeat steps 8-11 until the user guesses the word or runs
##          out of guesses.
##          a. If the user guesses the words, congratulate them.
##          b. If the user runs out of guesses pick one word at random from word_set
##              and tell the user that word was the word chosen the whole time.
##
##ERROR HANDLING:
##    Ensure that the user input is valid pertaining to parts of the program where
##    the user may be entering values that do not exist in sets or dictionaries.
##
##OTHER COMMENTS:
#################################
import random

# Functions
def read_file():
    """Read through a file, adding each word to a dictionary which maps words
        to the length of the word. Return the dictionary."""
    word_dict = {}
    word_file = open("dictionary.txt", "r")
    # iterate through each line and add the word_length : set_of_words to word_dict
    for line in word_file:
        # initalize a set of words if there isnt one already in the dictionary
        if len(line.strip()) not in word_dict:
            word_dict[len(line.strip())] = {line.strip().lower()}
        else:
            word_dict[len(line.strip())].add(line.strip().lower())
    word_file.close()
    return word_dict

def choose_word_len(word_dict):
    """Lets the user pick a specific word length. Ensures that the word length
        is in word_dict."""
    while True:
        word_length_str = input("How long of a word would you like to guess? ")
        word_length_str = word_length_str.strip()
        if word_length_str.isdigit():
            # convert to type int in order to check word_dict for valid input
            word_length_int = int(word_length_str)
            if word_length_int in word_dict:
                return word_length_int
            else:
                print("No word of that length was found. \nTry again.")
        else:
            print("Error. \nInvalid input!")

def supply_remaining_words():
    """Lets the user choose whether or not to have a print out of words
        remaining. Returns a bool"""
    while True:
        user_ans = input("Do you want the game to display the number of \
words remaining [Y/N]? ")
        user_ans = user_ans.strip().lower()
        if user_ans == 'y' or user_ans == 'yes':
            return True
        elif user_ans == 'n' or user_ans == 'no':
            return False
        else:
            print("Not a valid choice. \nTry again!")

def choose_guess_num():
    """Lets user pick the number of guesses they would like per game. Ensures
        that the user picks a number > 0."""
    while True:
        user_ans_str = input("How many guesses would you like to have: ")
        user_ans_str = user_ans_str.strip()
        # attempt to convert user's response to type int in order to be able
        # to subtract guesses later
        try:
            user_ans_int = int(user_ans_str)
            if user_ans_int > 0:
                return user_ans_int
            else:
                print("Must be greater than 0 in order for you to have a shot \
at winning this!")
        except ValueError:
            print("Invalid response. \nTry again!")

def print_game_info(user_letter_set, game_state_str, disp_rem_words_bool,\
                    word_set, guess_num_int):
    """Prints out all the information that the user will need for the game."""
    print("Guesses left:", guess_num_int)
    print("Letters you have chosen:", end =" ")
    for ch in sorted(user_letter_set):
        print(ch, end=" ")
    print("\nWord:", game_state_str)
    if disp_rem_words_bool:
        print("Words remaining:", len(word_set))

def choose_letter(alpha_set, user_letter_set):
    """Lets the user pick a letter from the alpha_set. Remove choice from
        alpha_set and add choice to user_letter_set."""
    valid_input_bool = False
    while not valid_input_bool:
        print("Letter choices remaining:", end=" ")
        for ch in sorted(alpha_set):
            print(ch, end= " ")
        user_choice_str = input("\nChoose a letter: ")
        user_choice_str = user_choice_str.strip().lower()
        # ensure that the user will pick a letter contained within alpha_set
        if user_choice_str in alpha_set:
            valid_input_bool = True
        else:
            print("The selection you have made is not contained within the list \
of remaining letters. \nPlease try again!")
    # remove letter form alpha_set and add to user_letter_set
    alpha_set.discard(user_choice_str)
    user_letter_set.add(user_choice_str)
    return user_choice_str

def determine_fam(word, letter_choice_str):
    """Takes the word and places it into a family catagory based upon the letter
        that the user has chosen."""
    if letter_choice_str not in word:
        return "-"*len(word)
    else:
        fam = ""
        for ch in word:
            if ch == letter_choice_str:
                fam += letter_choice_str
            else:
                fam += "-"
        return fam

def find_largest_fam(word_fam_dict, game_state_str):
    """Iterates through the word_fam_dict and determines which word family
        contains the most words."""
    max_set_len = 0
    for word_fam_str, word_set in word_fam_dict.items():
        if len(word_set) > max_set_len:
            largest_set = word_set
            largest_word_fam_str = word_fam_str
            max_set_len = len(word_set)
    # update game_state_str with the new word_fam
    game_state_str, game_state_change_bool = update_game_state \
                                             (game_state_str, largest_word_fam_str) 
    return largest_set, game_state_str, game_state_change_bool

def update_game_state(game_state_str, word_fam):
    """Updates the game_state_str to contain the proper value."""
    # convert game_state_str to a list. (making it mutable)
    game_state_list = list(game_state_str)
    # initalize a bool to determine is game_state has changed
    game_state_change_bool = False
    # iterate through new_game_state_str and update game_state_list
    # at the specific indecies where word_fam has a letter value
    for index, ch in enumerate(word_fam):
        if ch != "-":
            game_state_change_bool = True
            game_state_list[index] = ch
    return "".join(game_state_list), game_state_change_bool
    
        
# Main Program
word_dict = read_file()
# alphabetical set of letters left to choose from
alpha_set = set("abcdefghijklmnopqrstuvwxyz")
user_letter_set = set()

print("HANGMAN! \nThe object of the game is to guess the word.")
print("You supply the limit of how many guesses and the length of the word.")

word_len_int = choose_word_len(word_dict)
disp_rem_words_bool = supply_remaining_words()
guess_num_int = choose_guess_num()
# game_state will be used to display the current letters that are within
# the hidden word family
game_state_str = "-"*word_len_int
# initalize a set to hold words that are in play based on user word_len choice
word_set = word_dict[word_len_int]

# stay in a loop until the user runs out of guesses or somehow guesses the word
while guess_num_int > 0:
    print_game_info(user_letter_set, game_state_str, disp_rem_words_bool,\
                    word_set, guess_num_int)
    letter_choice_str = choose_letter(alpha_set, user_letter_set)

    # initalize a new dictionary which will group sets of words by their families
    word_fam_dict = dict()
    # iterate through each word in the word_set and group them into families
    # based upon the letter selection made by the user
    for word in word_set:
        word_fam_str = determine_fam(word, letter_choice_str)
        if word_fam_str not in word_fam_dict:
            word_fam_dict[word_fam_str] = {word}
        else:
            word_fam_dict[word_fam_str].add(word)
    # update word_set to contain a new set of words based upon the largest set
    # found in the word_fam_dict & initialize a variable (new_game_state)
    # which will be used to determine if the game_state has changed
    word_set, game_state_str, game_state_change_bool = \
              find_largest_fam(word_fam_dict, game_state_str)
    
    # game_state was not updated to a new state. (Letter not found in word)
    # subtract 1 from guess_num_int
    if not game_state_change_bool:
        print("Sorry, {} was not found in the word!".format(letter_choice_str))
        guess_num_int -= 1

    # user guesses the correct word
    if "-" not in game_state_str:
        print("Congratulations! \nYOU WIN!")
        print("You guessed the correct word, {}, with {} guesses to go!".format \
              (game_state_str, guess_num_int))
        break

# user runs out of guesses. (while loop ends normally)
# pick a word at random from word_set and tell user it was the word all along
else:
        word_all_along_str = random.choice(list(word_set))
        print("Sorry you are out of guesses. \nGAME OVER!.")
        print("The word you should of guessed was:", word_all_along_str)
        
