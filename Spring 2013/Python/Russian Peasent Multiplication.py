##CS 101
##Program 2
##William Freeman
##wjfkc2@mail.umkc.edu
##
##PROBLEM:
##    Create a program that will implement an algorithm for multiplying integers
##    known as Ancient Egyptian multiplication of Russian Peasant multiplication.
##    Ask the user to input 2 int values, A & B then follow the algorithm for
##    the multiplication of the two numbers
##
##ALGORITHM:
##    1. Initalize program repetion value as True 
##    2. While repetion value is true
##        (Set the total product and temp_B to 0)
##        i.) Prompt user to enter two integers A & B and
##            convert A & B from string to int
##            (assume user will enter an int value)
##        ii.) If B is a negative value
##            a.) Assign a temp_B variable to B 
##                 (in order to determine if total is positive or negative)
##            b.) Convert value of B to a positive value (for int division)
##        iii.) While B > 0
##            a.) Output value of A & B
##            b.) If B is odd add the value of A to total 
##                 (output that this is happening to user)
##            c.) multiply A by 2 and use inter division on B by 2
##         iv.) If A and temp_B are both negative then the total is positive
##         v.) If the total is positive and temp_B is negative
##              then total is negative
##         vii.) Output wether or not total is positive or negative
##                and the value of total
##         vii.) Prompt the user to continue
##            a.) If user answers no change repetion value to False
##
##ERROR HANDLING:
##    NONE(Assume user inputs 2 integers)
##
##OTHER COMMENTS:
#################################
# initialize program repetition for while loop
# Set the total product and temp_B to 0 within the repetition loop
# Do this to clear the values when a user goes another round
run_again_bool = True
while run_again_bool == True:
    total_int = 0
    temp_B_int = 0
    # Prompt the user to enter two integers and convert to type int
    # Assume the user will actually use proper int values
    print('LETS GET READY FOR SOME RUSSIAN PEASANT MULTIPLICATION!')
    A_int = int(input('Enter the first integer : '))
    B_int = int(input('Enter the second integer : '))

    # If B_int is a negative value assign variable temp_B_int to B_int
    # So that later the sign of total_int can be determined
    # Change B_int from negative to positive (for int division)
    if B_int < 0:
        temp_B_int = B_int
        B_int = abs(B_int)

    # Begin the Russian Peasant multiplication
    while B_int > 0:
        # Output current values of A_int and B_int to user
        print('A =', A_int, ', B =', B_int)
        
        # If B_int is odd, add the current value of A_int to total_int
        # Output that this is happening to user
        if B_int % 2 != 0:
            total_int += A_int
            print('B is odd, adding', A_int, 'to product to get', total_int)

        # Multiply A_int by 2 and integer divide B_int by 2
        A_int *= 2
        B_int = B_int // 2

    # If both A_int and temp_B_int are negative
    # Change the total_int from negative to positive
    # If total_int is positive and temp_B_int is negative
    # Change the total_int from positive to negative
    if A_int < 0 and temp_B_int < 0:
        total_int = -total_int
    elif total_int > 0 and temp_B_int < 0:
        total_int = -total_int

    # Let user know if total_int is positive or negative
    # Output total_int to user
    if total_int > 0:
        print('Product is positive.')
    elif total_int == 0:
        print('Product is zero...')
    else:
        print('Product is negative.')
    print('Your final product is :', total_int)
    
    # Ask the user if they would like to continue 
    # Take into account all possible user inputs
    # Initialize valid_input_bool as False
    # Once user inputs a valid response set vaid_input_bool to True
    valid_input_bool = False
    while valid_input_bool == False:
        rpt_ans_str = input('Do you wish to go again? (Y/N): ')
        if rpt_ans_str == 'N' or rpt_ans_str == 'n' or rpt_ans_str == 'No' \
           or rpt_ans_str == 'NO' or rpt_ans_str == 'no':
            print('GOODBYE!')
            valid_input_bool = True
            run_again_bool = False
        elif rpt_ans_str == 'Y' or rpt_ans_str == 'y' or rpt_ans_str == 'Yes' \
             or rpt_ans_str == 'YES' or rpt_ans_str == 'yes':
            valid_input_bool = True
        else:
            print('Error please input a proper response.')
        
