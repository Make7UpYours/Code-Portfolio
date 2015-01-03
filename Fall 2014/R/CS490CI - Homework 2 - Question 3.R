# (a) Which answer is correct, and why?
# i. For a fixed value of IQ and GPA, males earn more on average than females.
# ii. For a fixed value of IQ and GPA, females earn more on average than males.
# iii. For a fixed value of IQ and GPA, males earn more on average than females provided that the GPA is high enough.
# iv. For a fixed value of IQ and GPA, females earn more on average than males provided that the GPA is high enough.
GPA = seq(0,4,by = .1) # GPA ranging from 0-4.0 seperated by .1 between each GPA
IQ = seq(70,140, by = 10) # IQ ranging from 70-140 seperated by 10 between each IQ
m_Sal = matrix(0,1,41)
f_Sal = matrix(0,1,41)
count = 1

for(i in IQ){
  for(j in GPA){
    m_Sal[count] = 50 + (20 + 0.01*i)*j + 0.07*i
    f_Sal[count] = 85 + (10 + 0.01*i)*j + 0.07*i
    count = count + 1
  }
  count = 1
  plot(GPA,m_Sal,"l", col = "red", main = "Salary Earned vs. GPA", ylab = "Salary in Thousands",
       lwd = 2.5)
  lines(GPA,f_Sal, col = "blue", lwd = 2.5)
  legend(3.4, 80, c("Male", "Female"), lty = c(1,1), lwd = c(2.5,2.5), col = c("red", "blue"))
}

# (b) Predict the salary of a female with IQ of 110 and GPA of 4.0.
IQ = 110
GPA = 4.0
Sal = 85 +(10 + 0.01*IQ)*GPA + 0.07*IQ