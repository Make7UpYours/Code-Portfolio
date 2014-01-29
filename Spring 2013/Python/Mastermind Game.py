##CS 101
##Program 5
##William Freeman
##wjfkc2@mail.umkc.edu
##
##PROBLEM:
##    Create a game of Mastermind. Generate a random 4-digit sequence not
##    repeating any 1 digit and then allow the user to attempt to guess the
##    sequence giving them hints along the way and limiting their attempts to
##    12 attempts total.
##
##ALGORITHM:
##     1. Randomly generate a 4-digit number sequence, ensuring that no one
##        digit is repeated.
##        a. Initialize a varible guess_count which keeps track of the number
##           of user guesses.
##     2. Ask the user for a guess of the 4-digit random number sequence.
##        a. Check the user's input and verify that the input is valid.
##           (no repeated digits and ensure the sequence is all digits)
##        b. Check the user's numerical guess, one digit at a time and compare
##           that to the random number sequence.
##           i. If the digit is in the number and in the correct location,
##              add an 'X' to a hint_list.
##           ii. If the digit is in the number but not in the correct location,
##               add an 'O' to a hint_list.
##           iii. If the digit is not found within the random number sequence,
##                add an '-' to a hint_list.
##     3. Sort the hint_list(X's first, O's second, -'s last). Store the
##        hint_list as well as the user's guess sequence in a list for
##        later output.
##     4. Output to the user their current guess and current hint_list, as well
##        as the previous guesses and hints as well.
##        a. Add 1 to the guess_count.
##     5. Continue allowing the user to make guesses until a guess_limit of 12
##        is reached or until the user guesses the random number sequence.
##        a. Output the random number sequence if the user exceeds the
##           guess_limit.
##
##ERROR HANDLING:
##    Ensure that the user will enter valid input and will only enter a 4 digit
##    number sequence without repeating numbers.
##
##OTHER COMMENTS:
#################################
import random

# functions
def generate_random_seq():
    """Creates a random sequence of 4 digits and returns them as a string."""
    num_list = ["0","1","2","3","4","5","6","7","8","9"]
    random_seq_list = random.sample(num_list, 4)
    return "".join(random_seq_list)

def obtain_user_seq(count_int):
    """Obtains a user's sequence of 4-digits and ensures valid input."""
    # Initalize a bool to determine if the user has valid input
    valid_response_bool = False
    print("-"*20)
    print("Guess Number:", count_int)
    print("-"*20)
    # continue to loop until the user enters a valid sequence
    while not valid_response_bool:
        # initalize a value to determine if the user has repeated digits
        rpt_digits_bool = False
        user_guess_str = input("Enter a guess: ").strip()
        # not valid input if the user exceeds the length limit of 4 digits
        # or the input is not all digits
        if not user_guess_str.isdigit() or len(user_guess_str) != 4:
            print("Not a valid guess try again!")
            continue
        # ensure user does not repeat digits
        else:
            user_guess_list = list(user_guess_str)
            for digit in user_guess_list:
                if user_guess_list.count(digit) > 1:
                    print("Do not repeat digits!")
                    print("Try again.")
                    rpt_digits_bool = True
                    # break from for loop, no need to test any other values
                    break
            # if the user has not repeated any digits and the program
            # has made it this far down the loop then the user has
            # valid input for the program
            if not rpt_digits_bool:
                valid_response_bool = True
    return user_guess_str

def hint_func(user_str, rand_str):
    """Iterates through the user_str and compares the digits to the digits in
        rand_str returning a string of a sorted hint_list."""
    # initalize an empty hint_list and a proper starting value for index
    hint_list = []
    index = 0
    while index < len(user_str):
        if user_str[index] == rand_str[index]:
            hint_list.append("X")
            index += 1
        elif user_str[index] in rand_str:
            hint_list.append("O")
            index += 1
        else:
            hint_list.append("-")
            index += 1
    # reverse the sort() in order to obtain proper output for our hints
    hint_list.sort(reverse = True)
    return "".join(hint_list)

def print_prev_tries(prev_tries_list):
    """Prints the previous attempts by the user along with the result of the hint
        the user recieved."""
    for tup in prev_tries_list:
        print(tup[0], "\t", tup[1])
    
def rpt_prgm_question():
    """Asks the user if they would like to continue, will return a bool
        which will either continue the loop or break the main loop."""
    # Continue to repeat until a valid response is given by the user
    while True:
        rpt_ans_str = input("Would you like to go again (Y/N)? ").strip().lower()
        if rpt_ans_str == "n" or rpt_ans_str == "no":
            rpt_bool = False
            break
        elif rpt_ans_str == "y" or rpt_ans_str == "yes":
            rpt_bool = True
            break
        else:
            print("Invalid response please try again!")
            continue
    return rpt_bool

# main program
prgm_rpt_bool = True
# Repeat program until the user says to stop
while prgm_rpt_bool:
    # initalize guess count as well as an empty list that will be used to
    # store and display the previous attempts to the user
    guess_count_int = 1
    prev_tries_list = []
    # Print instructions, for noobs
    print("""WELCOME TO MASTERMIND!
INSTRUCTIONS: There is a randomly generated 4-digit number in which you are
attempting to guess within 12 tries. Each attempt that you make you will be
given a hint to go along with your attempt. There are no repeated digits within
the sequence and all digits 0-9 are valid.
HINTS: X = there is a digit within your guess that is in the correct location.
O = there is a digit within your guess that is in the random number but not in
the correct location.
- = there is a digit within your guess that is not in the random number sequence.
WARNING: Hints are not necessarily in order!!! Meaning that just because XXO- is
your hint that does not mean that the first 2 digits of your guess is in the correct
location!
LETS BEGIN SHALL WE?""")
          
    random_seq_str = generate_random_seq()
    # Continue to allow guesses until the guess limit of 12 is reached
    while guess_count_int <= 12:
        user_guess_str = obtain_user_seq(guess_count_int)
        # user guesses the correct number
        if user_guess_str == random_seq_str:
            print("Congratulations you win!")
            print("*"*18)
            print("TOTAL TRIES: ", guess_count_int)
            break
        hint_str = hint_func(user_guess_str, random_seq_str)
        # append a tuple of the user's current guess and the hint_str to a list
        # for outputting to the user later
        prev_tries_list.append((user_guess_str, hint_str))
        print_prev_tries(prev_tries_list)
        guess_count_int += 1
    else:
        # If the user runs out of tries, let them know the number
        print("Guess limit exceeded.")
        print("YOU LOSE!")
        print("*"*8)
        print("The number was :", random_seq_str)
    prgm_rpt_bool = rpt_prgm_question()
