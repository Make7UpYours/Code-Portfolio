# In this exercise, we will predict the number of applications received using
# the other variables in the College data set.
library(ISLR)
library(glmnet)
library(pls)
attach(College)
summary(College)
dim(College)
set.seed(75)

# (a)  Split the data set into a training set and a test set.
observations = dim(College)[1]
trainIndecies = sample(observations, observations / 2)
college.testSet = College[-trainIndecies,]
college.trainSet = College[trainIndecies,]

# (b)  Fit a linear model using least squares on the training set, and report the
# test error obtained.
college.fit = lm(Apps~., data=college.trainSet)
college.pred = predict(college.fit, college.testSet)
error = mean((Apps - predict(college.fit, College))[-trainIndecies]^2)

# (c)  Fit a ridge regression model on the training set, with lambda chosen by
# cross-validation. Report the test error obtained.
x = model.matrix(Apps~., data = College)[,-1]
y = College$Apps
grid=10^seq(10,-2,length=100)
ridge.mod = cv.glmnet(x[trainIndecies,],y[trainIndecies],alpha=0,lambda=grid)
ridge.bestlam = ridge.mod$lambda.min
ridge.bestlam
ridge.pred=predict(ridge.mod,s=ridge.bestlam,newx=x[-trainIndecies,])
error1 = mean((ridge.pred-y[-trainIndecies])^2)
error1

# (d)  Fit a lasso model on the training set, with ?? chosen by cross-validation.
# Report the test error obtained, along with the number of non-zero coefficient
# estimates.
lasso.mod = cv.glmnet(x[trainIndecies,],y[trainIndecies],alpha=1,lambda=grid)
lasso.bestlam = lasso.mod$lambda.min
lasso.bestlam
lasso.pred=predict(lasso.mod,s=lasso.bestlam,newx=x[-trainIndecies,])
error2 = mean((lasso.pred-y[-trainIndecies])^2)
error2

# (e)  Fit a PCR model on the training set, with M chosen by cross-validation.
# Report the test error obtained, along with the value of M selected by cross-validation.
pcr.fit = pcr(Apps~., data=college.trainSet, scale=TRUE, validation="CV")
validationplot(pcr.fit,val.type="MSEP")
pcr.pred = predict(pcr.fit,x[-trainIndecies,],ncomp=16)
error3 = mean((pcr.pred-y[-trainIndecies])^2)
error3

# (f)  Fit a PLS model on the training set, with M chosen by cross-validation. Report the
# test error obtained, along with the value of M selected by cross-validation.
pls.fit = plsr(Apps~., data=college.trainSet, scale=TRUE, validation="CV")
validationplot(pls.fit,val.type="MSEP")
pls.pred = predict(pls.fit,x[-trainIndecies,],ncomp=6)
error4 = mean((pls.pred-y[-trainIndecies])^2)
error4
