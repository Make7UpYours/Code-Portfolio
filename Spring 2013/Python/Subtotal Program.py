##CS 101
##Program 1
##William Freeman
##wjfkc2@mail.umkc.edu
##
##PROBLEM: Ask the user for the subtotal of a purchase, and for the tax rate.
##   Compute and print the total.
##
##ALGORITHM:
##      1. Prompt input from user for the subtotal and the tax rate 
##      (as a percentage) of a purchase.
##      2. Convert the tax rate and subtotal from strings to floats.
##      (So we can perform mathmatical operations)
##      3. Assign the cost of tax to (tax rate/100)*subtotal 
##      (by dividing the tax rate by 100 this converts the tax rate to decimal 
##      form and multiplying that quantity by subtotal will provide the cost of
##      tax for the purchase) 
##      4. Calculate the purchase total using the formula: subtotal + cost of
##      tax.
##      5. Output total.
##
##ERROR HANDLING: NONE
##
##OTHER COMMENTS: NONE
################################################################################
# Obtain the subtotal and tax_rate from the user & convert str to float
subtotal_float = float(input("What is the subtotal of the purchase? "))
tax_rate_float = float(input("What is the tax rate, as a percentage? "))

# Calculate the cost of tax for the purchse and the total
tax_cost_float = (tax_rate_float / 100) * subtotal_float
total_float = tax_cost_float + subtotal_float

# Display user's total
print("Your total is : $" , total_float)
