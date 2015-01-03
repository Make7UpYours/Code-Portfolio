library(ISLR)
library(glmnet)
attach(Wage)
summary(Wage)

# (b) Fit a step function to predict wage using age, and perform
# cross-validation to choose the optimal number of cuts. Make
# a plot of the fit obtained.

# Finding the optimal number of cuts.
cv.error = matrix(,20)
for(i in 2:20){
  Wage$cut = cut(age,i)
  fit = glm(wage~cut, data=Wage)
  cv.error[i] = cv.glm(Wage, fit, K=10)$delta[1]
}
cv.error

# Plotting the fit.
lm.fit = lm(wage~cut(age,8),data=Wage)
agelims = range(age)
age.grid=seq(from=agelims[1],to=agelims[2])
pred = predict(lm.fit, data.frame(age=age.grid))
plot(wage~age, data=Wage, col=8)
title("Age vs. Wage Step-Function")
lines(age.grid, pred, col="red", lwd=3)

