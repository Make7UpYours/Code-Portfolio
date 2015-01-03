library(ISLR)
library(MASS)
library(class)
attach(Auto)

# (a)  Create a binary variable, mpg01, that contains a 1 if mpg contains
# a value above its median, and 0 if mpg contains a value below its median.
# You can compute the median using the median() function. Note you may find
# it helpful to use the data.frame() function to create a single data set
# containing both mpg01 and the other Auto variables.

mpg01 = matrix(0,length(mpg),1)
for(i in 1:length(mpg)){
  if(mpg[i] > median(mpg)){
    mpg01[i] = 1
  }
}
Auto = data.frame(Auto, mpg01)

# (b)  Explore the data graphically in order to investigate the association
# between mpg01 and the other features. Which of the other features seem most
# likely to be useful in prediction mpg01? Scatterplots and boxplots may be 
# useful tools to answer this question. Describe your findings.

cor(Auto[,-9])
pairs(Auto)

# (c)  Split the data into a training set and a test set.

train = matrix(0, length(mpg),1)
ran.sample = sample(1:length(mpg), length(mpg)/3, replace=F)
# Place the indicies of ran.sample into training set.
for(i in 1:length(mpg)){
  if(i %in% ran.sample){
    train[i] = TRUE
  }
}
test = !train
Auto.test = Auto[test,]
mpg01.test = mpg01[test,]
train = !(!train)

# (d)  Perform LDA on the training data in order to predict mpg01 using the
# variables that seemed most associated with mpg01 in (b). What is the test
# error of the model obtained?

lda.fit = lda(mpg01~cylinders+weight+displacement+horsepower,
              data=Auto, family=binomial, subset=train)
lda.pred = predict(lda.fit, Auto.test)
mean(lda.pred$class != mpg01.test)

# (e)  Perform QDA on the training data in order to predict mpg01 using the
# variables seemed the most associated with mpg01 in (b). What is the test 
# error of the model obtained?

qda.fit = qda(mpg01~cylinders+weight+displacement+horsepower,
              data=Auto, family=binomial, subset=train)
qda.pred = predict(qda.fit, Auto.test)
mean(qda.pred$class != mpg01.test)

# (f)  Perform logistic regression on the training data in order to predict
# mpg01 using the variables that seemed most associated with mpg01 in (b).
# What is the test error of the model obtained?

glm.fit = glm(mpg01~cylinders+weight+displacement+horsepower,
              data=Auto, family=binomial, subset=train)
glm.probs = predict(glm.fit, Auto.test, type="response")
glm.pred = rep(0, length(glm.probs))
glm.pred[glm.probs > 0.5] = 1
mean(glm.pred != mpg01.test)

# (g)  Perform KNN on the training data, with several values of K, in order
# to predict mpg01. Use only the variables that seemed the most associated with
# mpg01 in (b). What test errors do you obtain? Which value of K seems to perform
# the best on this data set?

train.X = cbind(cylinders, weight, displacement, horsepower)[train,]
test.X = cbind(cylinders, weight, displacement, horsepower)[test,]
train.mpg01 = mpg01[train]
set.seed(1)
knn.pred = knn(train.X, test.X, train.mpg01, k=1)
mean(knn.pred != mpg01.test) # KNN, k=1
knn.pred = knn(train.X, test.X, train.mpg01, k=10)
mean(knn.pred != mpg01.test) # KNN, k=10
knn.pred = knn(train.X, test.X, train.mpg01, k=25)
mean(knn.pred != mpg01.test) # KNN, k=25
knn.pred = knn(train.X, test.X, train.mpg01, k=50)
mean(knn.pred != mpg01.test) # KNN, k=50
knn.pred = knn(train.X, test.X, train.mpg01, k=75)
mean(knn.pred != mpg01.test) # KNN, k=75
knn.pred = knn(train.X, test.X, train.mpg01, k=100)
mean(knn.pred != mpg01.test) # KNN, k=100