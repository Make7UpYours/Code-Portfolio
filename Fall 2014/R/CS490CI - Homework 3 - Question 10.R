library(ISLR)
library(MASS)
library(class)
attach(Weekly)

# (b)  Use the full data set to perform a logistic regression
# with Direction as the response and the five lag variables plus
# Volume as predictors. Use the summary function to print the results.
# Do any of the predictors appear to be statistically significant?
# If so, which ones?

weekly.fit = glm(Direction~Lag1+Lag2+Lag3+Lag4+Lag5+Volume,
              data=Weekly, family=binomial)
summary(weekly.fit)

# (c)  Compute the confusion matrix and overall fraction of correct
# predictions. Explain what the confusion matrix is telling you about
# the types of mistakes made by logistic regression.

weekly.probs = predict(weekly.fit, type="response")
weekly.pred = rep("Down", length(weekly.probs))
weekly.pred[weekly.probs>.5] = "Up"
table(weekly.pred, Direction)

# (d)  Now fit the logistic regression model using a training data
# period from 1990 to 2008, with Lag2 as the only predictor. 
# Compute the confusion matrix and the overall fraction of correct
# predictions for the held out data (that is, the data from 2009 and 2010).

train = (Year < 2009)
Weekly2.2009 = Weekly[!train,]
weekly2.fit = glm(Direction~Lag2, data=Weekly, family=binomial, subset=train)
weekly2.probs = predict(weekly2.fit, Weekly2.2009,type="response")
weekly2.pred = rep("Down", length(weekly2.probs))
weekly2.pred[weekly2.probs>.5] = "Up"
Direction.2009 = Direction[!train]
table(weekly2.pred, Direction.2009)
mean(weekly2.pred == Direction.2009)

# (e)  Repeat (d) using LDA.

weekly.lda.fit = lda(Direction ~ Lag2, data=Weekly, subset=train)
weekly.lda.pred = predict(weekly.lda.fit, Weekly2.2009)
table(weekly.lda.pred$class, Direction.2009)
mean(weekly.lda.pred$class == Direction.2009)

# (f)  Repeat (d) using QDA.

weekly.qda.fit = qda(Direction~Lag2, data=Weekly, subset=train)
weekly.qda.class = predict(weekly.qda.fit, Weekly2.2009)$class
table(weekly.qda.class, Direction.2009)
mean(weekly.qda.class == Direction.2009)

# (g)  Repeat (d) using KNN with K = 1.

train.X = cbind(Lag2[train])
test.X = cbind(Lag2[!train])
train.Direction = Direction[train]
set.seed(1)
weekly.knn.pred = knn(train.X, test.X, train.Direction, k=1)
table(weekly.knn.pred, Direction.2009)
mean(weekly.knn.pred == Direction.2009)