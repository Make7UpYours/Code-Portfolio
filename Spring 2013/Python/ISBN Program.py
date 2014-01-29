##CS 101
##Program 3
##William Freeman
##wjfkc2@mail.umkc.edu
##
##PROBLEM:
##              Create a program in which a user will enter the first 9-digits
##              of an ISBN number. Then calculate the check symbol using
##              the method of finding the check sum and then determining
##              the remainder of the sum divided by 11. Output the full ISBN
##              and the check symbol in proper format.
##
##ALGORITHM:
##              1. Initialize program repetition boolean value as True.
##              2. While repetion value is true.
##                  i.) Initialize a boolean value to determine if user has
##                      entered a correct 9-digit ISBN number as false and
##                      initialize the check sum to zero.
##                  ii.) While the ISBN boolean value is False.
##                      a.) Prompt the user to input a 9-digit ISBN number.
##	          b.) Check the user's input for a correct 9-digit value, if
##                           value is correct change the proper ISBN input
##                           boolean to True, if not let the user know they used
##                           an invalid input.
##                  iii.) Determine the check sum value using the formula:
##                        1*first digit + 2*second + 3*thrid...+9*ninth digit.
##                  iv.) Divide the check sum value by 11 and if the remainder
##                        is 0-9, then the remainder is the check symbol, if the
##                        remainder is 10 then X is the check symbol.
##                  v.) Output the full 10-digit ISBN number with the check
##                       symbol in the format: x-xxx-xxxxx-x.
##	      vi.) Initialize a boolean value for proper quit question
##                        response as False.
##                  vii.) While the proper quit response boolean value is False.
##                      a.) Ask the user if they would like to repeat the program.
##                      b.) If user responds yes, set the proper response boolean
##                           to True.
##                      c.) If user responds no, set the proper response boolean to
##                           True and the program repetition boolean value to False.
##                      d.) If user inputs an invalid response...Let them know.
##
##ERROR HANDLING:
##                  Make sure the user inputs a correct 9-digit ISBN number and
##                  make sure that what the user inputs is indeed a numerical
##                  value. Upon exit, ensure that the user makes a valid response
##                  when asked to quit.
##
##OTHER COMMENTS:
####################################################################
# Print welcome message
print("-" * 20)
print("WELCOME!")
print("-" * 20)

# Initialize a program repetition boolean value as True
# Value will be used to control the overall program loop
program_rpt_bool = True

while program_rpt_bool:
    # Initialize a boolean value as False to control proper input
    # Initialize the check sum value to 0
    proper_ISBN_bool = False
    check_sum_int = 0
    while not proper_ISBN_bool:
        ISBN_nine_str = input("Please enter a 9-digit ISBN number: ")
        ISBN_nine_str = ISBN_nine_str.strip()

        # Test for proper length of 9 and test see if input is a valid digit
        if len(ISBN_nine_str) == 9 and ISBN_nine_str.isdigit():
            proper_ISBN_bool = True
        else:
            print("This is not a 9-digit number please try agian!")

    # Calculate the check sum using formula:
    # 1*first digit + 2*second + 3*thrid...+9*ninth
    for index_int in range(len(ISBN_nine_str)):
        check_sum_int += (index_int +1) * int(ISBN_nine_str[index_int])

    # Find the check symbol by determining the remainder of
    # the check sum / 11
    # The remainder will then be the check symbol, unless
    # the remainder is 10. Then the check symbol is X
    check_symbol_str = str(check_sum_int % 11)
    if check_symbol_str == "10":
        check_symbol_str = "X"

    # Output the full 10-digit ISBN with the check symbol
    # Use format: x-xxx-xxxxx-x
    print("Your full ISBN with check symbol is: " \
          + ISBN_nine_str[0] + "-" + ISBN_nine_str[1:4] + "-" \
          + ISBN_nine_str[4:] + "-" + check_symbol_str)

    # Initialize a boolean value as False to determine proper response
    # Ask user if they would like to continue with the program or quit
    # Provide a proper response if user inputs invalid response
    proper_repetition_input_bool = False
    while not proper_repetition_input_bool:
        repetition_str = input("Would you like to go again? [Y/N] ")
        repetition_str = repetition_str.strip().lower()
        if repetition_str == "y" or repetition_str == "yes":
            proper_repetition_input_bool = True
        elif repetition_str == "n" or repetition_str == "no":
            print("-" * 20)
            print("GOODBYE!")
            print("-" * 20)
            proper_repetition_input_bool = True
            program_rpt_bool = False
        else:
            print("ERROR: INVALID INPUT!")
        
