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
import string
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

def clean_word_list(word_list):
    """Cleans up the word list getting rid of bad characters and duplicate words"""
    narrowed_word_list = []
    bad_chars = string.punctuation + " "
    for word in word_list:
        word = word.strip().lower()
        if bad_chars in word:
            for char in word:
                word = word.replace(char, "")
        narrowed_word_list.append(word)
    # Changing to a set and back to a list will get rid of duplicate words
    return list(set(narrowed_word_list))

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
    letters_list = list(test_word)
    trial_letter_list = list(trial_word)
    letters_list.sort()
    trial_letter_list.sort()
    sorted_test_word = "".join(letters_list)
    sorted_trial_word = "".join(trial_letter_list)
    # If the sorted letters are not the equal then the twoi words are
    # not anagrams
    if sorted_test_word != sorted_trial_word:
        is_anagram = False
    else:
        is_anagram = True    
    return is_anagram

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
word_list = main_file.readlines()
main_file.close()
# Clean the list, getting rid of duplicates and bad chars
narrowed_word_list = clean_word_list(word_list)
count_list = []
max_word_list = []

# Iterate through the list and test each word for anagrams
for test_word in narrowed_word_list:
    anagram_count = count_anagrams(test_word, narrowed_word_list)
    max_word_list = max_anagram_word(test_word, count_list, max_word_list)
    # Create a list of our anagram count for output
    count_list.append(anagram_count)
output(count_list, max_word_list)
print("*"*20)
print("WELL THAT WAS FUN BYE!")
print("*"*20)
    


    
