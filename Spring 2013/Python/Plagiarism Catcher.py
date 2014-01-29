##CS 101
##Program 7
##William Freeman
##04/19/2013
##wjfkc2@mail.umkc.edu
##
##PROBLEM:
##    Compare various text files for 6-word phrases containied within each
##    file to the other text files in an attempt to catch a plagiarists. If
##    there are more than 200 similar phrases between two text files then
##    those files are suspect of one another.
##
##ALGORITHM:
##    1. Prompt the user for the subfolder in which the text files are located.
##       Ensuring that thefolder does indeed exist. Reprompt if it does not.
##    2. Make the subfolder the current working directory.
##    3. For each file contained within the subfolder open read each text file
##       as one large string and assign to a variable. Close text file after it
##       is read.
##       a. Remove all punctuation from the string and make all words lowercase.
##       b. Split the file_str into a list_of_str, splitting on spaces.
##       c. Slice out all the 6-word phrases contained within the list_of_str and add
##           the phrases to a set_of_phrases.
##       d. Create a dictionary which maps filenames to set_of_phrases contained
##           within each text file.
##    4. Assign a variable which contains the filenames found within the filename_dict.
##        a. Iterate through each filename and compare every 6-word phrase assigned
##            to the filename with every 6-word phrase found in other filenames until
##            there is only 1 filename left in filename_dict.
##            i. Initalize a variable to keep track of the num_of_sim_phrases.
##            ii. If the 6-word phrase is found within other filenames add 1 to
##               num_of_sim_phrases.
##            iii. When the current filename finishes comparing phrases with another
##                 filename, if the num_of_sim_phrases > 200 then tuple the two file
##                 names together and create a set containing pairs_of_suspects
##            iv. Delete the current filename from the filename_dict, no longer needed.
##    5. Output to user the pairs of filenames that are suspect of plagiarism.
##    6. Move back into the starting working directory.
##
##ERROR HANDLING:
##    When the user is prompted to enter the subfolder name, verify that the
##    subfolder does exist.
##
##OTHER COMMENTS:
#################################
import os, os.path, string

# functions
def welcome():
    """Prints some information about the program and welcomes the user."""
    print("-----Welcome " + os.getlogin() + "!-----")
    print("""Program Information:
This program is designed to catch plagiarism by comparing text files.

You specificy the folder in which the text files are located that you would like
to compare. The program will compare these files and determine if any are
suspects for plagiarism.\n""")
          
def sub_folder():
    """Prompts the user for the subfolder that contains the text files. Ensures
       that the subfolder does exist before returning a value."""
    # keep looping until a valid subfolder is entered
    while True:
        subfolder = input("Name of subfolder where files are located: ")
        if not os.path.isdir("./" + subfolder):  # subfolder not found
            print("The subfolder you requested was not found.\n")
        else:
            return subfolder

def read_file(file_name):
    """Reads through each file, stripping puncuation and making all letters
        lowercase."""
    file = open(file_name, "r")
    # read through the whole file, .readlines() is a list of lines
    content_list = file.readlines()
    file.close() # done with file
    # join content_list together to make one large string
    content_str = "".join(content_list)
    content_str = content_str.lower()
    # remove punctuation
    for ch in string.punctuation:
        content_str = content_str.replace(ch, "")
    # replace tab chars & newline chars with whitespace
    for ch in "\n\t\r":
        content_str = content_str.replace(ch, " ")
    # return a list of words found in the file
    return content_str.split()

def slice_phrases(file_contents_list):
    """Slices out 6-word phrases from the given word list and returns them as
        a set of phrases."""
    # initalize start and end index values for slicing
    start_idx = 0
    end_idx = 6
    phrase_set = set()
    while end_idx < len(file_contents_list):
        # slice out each 6-word phrase
        phrase_list = file_contents_list[start_idx:end_idx]
        phrase_str = "".join(phrase_list)
        phrase_set.add(phrase_str)
        start_idx += 1
        end_idx += 1
    return phrase_set

def find_suspects(name_list, file_phrase_dict):
    """Iterates through the list of filenames and compares word phrases found
        within the file to other phrases found in other files. Returns a set of
        tuples of suspect files."""
    # Variable that will contain a set of suspect filenames tupled together
    suspect_set = set()
    for filename in name_list:
        phrase_set = file_phrase_dict[filename]
        for check_file, check_phrases in file_phrase_dict.items():
            # skip ccomparing filename to itself
            if check_file == filename:
                continue
            sim_phrase_num = count_phrases(phrase_set, check_phrases)
            # number of similar word phrases exceeds allowed amount
            if sim_phrase_num > 200:
                suspect_set.add((filename, check_file))
        # to prevent testing of the same pair of files twice delete the dict
        # entry for the filename that was just used
        del(file_phrase_dict[filename])
    return suspect_set
                

def count_phrases(phrase_set1, phrase_set2):
    """Iterates through phrase_set1 and checks to see if the word phrase is
        contained within phrase_set2, if it is then count is increased."""
    count = 0
    for word_phrase in phrase_set1:
        if word_phrase in phrase_set2:
            count += 1
    return count       
                
    
# main program
welcome()
folder = sub_folder()
# change current working directory to specified folder
os.chdir("./"+folder)
file_set = set(os.listdir())    # create a list of all files
file_phrase_dict = dict()    # variable maps filenames to word phrases
for file_name in file_set:
    if ".txt" not in file_name:
        # if for some reason there are other files that are not .txt files
        # in the directory. Skip that file and move to the next
        print("Skipping,", file_name, "not a .txt file")
        continue
    file_contents_list = read_file(file_name)
    phrase_set = slice_phrases(file_contents_list)
    # map filenames to sets of word phrases
    file_phrase_dict[file_name] = phrase_set
# assign a variable which contains a list of all filenames found within
# file_phrase_dict
name_list = list(file_phrase_dict.keys())
suspect_set = find_suspects(name_list, file_phrase_dict)

# output results
if suspect_set == set():    # no suspect files found
    print("\nNo files were found to be suspects of plagiarism.")
else:
    print("\nThese files appear to be suspect of one another:")
    for file_pair in suspect_set:
        print("\t" + file_pair[0] + " and " + file_pair[1])
# change the current working directory back to the original folder
os.chdir("..")
