# In the lab, a classification tree was applied to the Carseats
# data set after converting Sales into a qualitative response variable.
# Now we will seek to predict Sales using regression trees and related
# approaches, treating the response as a quantitative variable
library(ISLR)
library(tree)
library(randomForest)
attach(Carseats)
summary(Carseats)

# (a)  Split the data set into a training set and a test set.
set.seed(26)
observations = 1:nrow(Carseats)
train = sample(observations,dim(Carseats)[1]/2)
carSeats.train = Carseats[train,]
carSeats.test = Carseats[-train,]

# (b)  Fit a regression tree to the training set. Plot the tree, and
# interpret the results. What test MSE do you obtain?
carSeats.tree=tree(Sales~.,data=carSeats.train)
plot(carSeats.tree)
text(carSeats.tree,pretty=0)
title("Carseats Tree")
pred.carSeats = predict(carSeats.tree, carSeats.test)
mean((carSeats.test$Sales - pred.carSeats)^2)

# (c)  Use cross-validation in order to determine the optimal level of
# tree complexity. Does pruning the tree improve the test MSE?
cv.carSeats=cv.tree(carSeats.tree)
par(mfrow=c(1,2))
plot(cv.carSeats$size,cv.carSeats$dev,type="b")
plot(cv.carSeats$k,cv.carSeats$dev,type="b")
carSeats.prune=prune.tree(carSeats.tree,best=10)
par(mfrow=c(1,1))
plot(carSeats.prune)
title("Pruned Car Seats Tree")
text(carSeats.prune,pretty=0)
pred.prune = predict(carSeats.prune, carSeats.test)
mean((carSeats.test$Sales - pred.prune)^2)

# (d)  Use the bagging approach in order to analyze this data. What test
# MSE do you obtain? Use the importance() function to determine which
# variables are the most important.
bag.carSeats=randomForest(Sales~.,data=carSeats.train, mtry=10, importance=T)
importance(bag.carSeats)
pred.bag = predict(bag.carSeats, carSeats.test)
mean((carSeats.test$Sales - pred.bag)^2)

# (e)  Use random forests to analyze this data. What test MSE do you obtain?
# Use the importance() function to determine which variables are the most important.
# Describe the effect of m, the number of variables considered at each split, on the
# error rate obtained.
rf.carSeats=randomForest(Sales~.,data=carSeats.train,mtry=5,importance=T)
yhat.rf=predict(rf.carSeats,newdata=carSeats.test)
importance(rf.carSeats)
mean((carSeats.test$Sales - yhat.rf)^2)