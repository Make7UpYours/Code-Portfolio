##CS 101
##Program 4
##William Freeman
##wjfkc2@mail.umkc.edu
##
##PROBLEM:
##           Create a program that opens a user specified text file and finds
##           anagrams within the file that contains a list of words. Output the
##           number of words with specific counts of anagrams within the file
##           as well as a list of words which contain the most anagrams.
##
##ALGORITHM:
##      1. Prompt the user for which specific file to open
##          (take into any input errors).
##      2. Read through each word in the file and add the words to a list.
##      3. Iterate through the list testing each word for anagrams.
##          a. Compare the word's length, if they are not equal then they
##              are not anagrams.
##          b. If the two words are of equal length then iterate through each
##              character of the two words.
##          c. If the two words contain the exact same characters then
##              they are anagrams.
##          d. Assign the number of anagrams that our test word has to a variable.
##          e. Add the anagram count to a list.
##              i. Sort the list from lowest value to highest value.
##              ii. Find the max value of the list (This is the higest anagram count).
##              iii. If the test word has the max value then add that word to a
##                  list of max anagram words.
##              iv. Clear the list and start fresh if a new max is found.
##      4. Output the results of how many words had anagrams. As well as
##          list the highest anagram words.
##ERROR HANDLING:
##                     Take into account that the user could enter an invalid
##                     file name. Make sure this does not happen.
##
##OTHER COMMENTS:
#################################
# Functions
def file_open():
    """Open the specified file from the user"""
    # Keep looping until the user enters a vaild file name
    while True:
        try:
            file = open(input("Flie name: "))
            return file
        except IOError:
            print("File was not found please try again.")

def list_creation(file):
    """Create a list of all the words within the file and stip white space"""
    list_of_words = []
    for word in file:
        list_of_words.append(word.strip())
    return list_of_words

def count_anagrams(word, word_list):
    """Elimiate from the list words that cannot be anagrams and count the
        number of anagrams per word"""
    anagram_count = 0
    for value in word_list:
        # Skip over our current test word within the list,
        # Don't want to count itself as an anagram
        if word == value:
            continue
        # If the lengths of the two words are not the same then
        # they cannot be anagrams
        elif len(word) != len(value):
            continue
        else:
            is_anagram = find_anagram(word, value)
            if is_anagram:
                anagram_count += 1
    return anagram_count

def find_anagram(test_word, trial_word):
    """Determine if the which words are anagrams of the test word"""
    # Ensure that letter capitalization does not affect result
    letters_list = list(test_word.lower())
    trial_letter_list = list(trial_word.lower())
    letters_list.sort()
    trial_letter_list.sort()
    letters_list = remove_bad_chars(letters_list)
    trial_letter_list = remove_bad_chars(trial_letter_list)
    # Iterate through each character in the two lists and compare them
    # if one word contains characters that are the same as the other
    # break loop and set is_anagram to false
    for index in range(len(letters_list)):
        if letters_list[index] != trial_letter_list[index]:
            is_anagram = False
            break
        else:
            is_anagram = True    
    return is_anagram

def remove_bad_chars(letter_list):
    """Removes unwanted characters from our list that will affect results"""
    import string
    # include punctuation and spaces if words in our text file contain them
    # for removal
    bad_chars = string.punctuation + ' '
    for char in letter_list:
        if char == bad_chars:
            letter_list.remove(char)
    return letter_list

def max_anagram_word(word, count_list, max_word_list):
    """Create a list of words with the highest anagram count"""
    # If count_list is empty then the our first word must be the max count
    if count_list == []:
        max_word_list.append(word)
    elif anagram_count == max(count_list):
        max_word_list.append(word)
    # If the anagram_count is larger than the max, clear the list
    # and start fresh
    elif anagram_count > max(count_list):
        max_word_list = []
        max_word_list.append(word)
    return max_word_list
        
def output(anagram_count_list, max_word_list):
    """Output the results"""
    anagram_count_list.sort()
    index = 0
    while index <= max(count_list):
        # If there are no words with (index) number of anagrams then skip output
        if count_list.count(index) == 0:
            index += 1
            continue
        elif count_list.count(index) == 1:
            print("There was", count_list.count(index), "word with", index, \
                  "anagrams.")
        else:
            print("There were", count_list.count(index), "words with", index, \
                  "anagrams.")
        index += 1
    print("The highest anagram count is", max(count_list))
    if len(max_word_list) == 1:
        print("There was only one word which stands above all others!")
        print("This word has an anagram count of", index - 1, "anagrams.")
    else:
        print("These were the words with the highest anagram count of", index - 1, \
              "anagrams:")
    for word in max_word_list:
        print("\t", word)

# Main Program
print("*"*25)
print("LETS FIND US SOME ANAGRAMS!")
print("*"*25)
main_file = file_open()
word_list = list_creation(main_file)
main_file.close()
count_list = []
max_word_list = []

# Iterate through the list and test each word for anagrams
for test_word in word_list:
    anagram_count = count_anagrams(test_word, word_list)
    max_word_list = max_anagram_word(test_word, count_list, max_word_list)
    # Create a list of our anagram count for output
    count_list.append(anagram_count)
output(count_list, max_word_list)
print("*"*20)
print("WELL THAT WAS FUN BYE!")
print("*"*20)
    


    
