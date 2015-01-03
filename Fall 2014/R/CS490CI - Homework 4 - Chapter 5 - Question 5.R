library(ISLR)
summary(Default)
attach(Default)

TestErrCalc = function(){
  # i.  Split the sample set into a training set and a validation set.
  observations = dim(Default)[1]
  trainSet = sample(observations, observations/2)
  testSet = Default[-trainSet,]
  
  # ii.  Fit a multiple logistic regression model using only the training observations.
  defaultTrain.fit = glm(default~income+balance, data=Default, family=binomial,
                         subset=trainSet)
  
  # iii.	Obtain a prediction of default status for each individual in the validation set
  # by computing the posterior probability of default for that individual, and classifying
  # the individual to the default category if the posterior probability is greater than 0.5.
  default.pred = rep("No", observations/2)
  default.probs = predict(defaultTrain.fit, testSet, type="response")
  default.pred[default.probs > 0.5] = "Yes"
  
  # iv.	Compute the validation set error, which is the fraction of the observations in the
  # validation set that are misclassified.
  return(mean((default.pred != testSet$default)))
}

TestErrCalc2 = function(){
  # i.  Split the sample set into a training set and a validation set.
  observations = dim(Default)[1]
  trainSet = sample(observations, observations/2)
  testSet = Default[-trainSet,]
  
  # ii.  Fit a multiple logistic regression model using only the training observations.
  defaultTrain.fit = glm(default~income+balance+student, data=Default, family=binomial,
                         subset=trainSet)
  
  # iii.  Obtain a prediction of default status for each individual in the validation set
  # by computing the posterior probability of default for that individual, and classifying
  # the individual to the default category if the posterior probability is greater than 0.5.
  default.pred = rep("No", observations/2)
  default.probs = predict(defaultTrain.fit, testSet, type="response")
  default.pred[default.probs > 0.5] = "Yes"
  
  # iv.	Compute the validation set error, which is the fraction of the observations in the
  # validation set that are misclassified.
  return(mean((default.pred != testSet$default)))
}

# (a) Fit a logistic regression model that uses income and balance to predict default.
set.seed(75)
default.fit = glm(default~income+balance, data=Default, family=binomial)

# (b) Using the validation set approach, estimate the test error of this model.
# In order to do this, you must perform the following steps:
# i.	Split the sample set into a training set and a validation set.
observations = dim(Default)[1]
trainSet = sample(observations, observations/2)
testSet = Default[-trainSet,]

# ii.	Fit a multiple logistic regression model using only the training observations.
defaultTrain.fit = glm(default~income+balance, data=Default, family=binomial,
                       subset=trainSet)

# iii.	Obtain a prediction of default status for each individual in the validation set
# by computing the posterior probability of default for that individual, and classifying
# the individual to the default category if the posterior probability is greater than 0.5.
default.pred = rep("No", observations/2)
default.probs = predict(defaultTrain.fit, testSet, type="response")
default.pred[default.probs > 0.5] = "Yes"

# iv.	Compute the validation set error, which is the fraction of the observations in the
# validation set that are misclassified.
error = mean((default.pred != testSet$default))

# (c)  Repeat the process in (b) three times, using three different splits of the observations
# into a training set and a validation set. Comment on the results obtained.
error1 = TestErrCalc()
error2 = TestErrCalc()
error3 = TestErrCalc()
errorSet = matrix(0,3)
errorSet[1] = error1
errorSet[2] = error2
errorSet[3] = error3
MSE = (error1 + error2 + error3) / 3
var(errorSet)

# (d)  Now consider a logistic regression model that predicts the probability of default using
# income, balance, and a dummy variable for student. Estimate the test error for this model using
# the validation set approach. Comment on whether or not including a dummy variable for student
# leads to a reduction in the test error rate.
testErrorSet = matrix(0,3)
testErrorSet[1] = TestErrCalc2()
testErrorSet[2] = TestErrCalc2()
testErrorSet[3] = TestErrCalc2()
TestMSE = sum(testErrorSet) / 3
var(testErrorSet)
