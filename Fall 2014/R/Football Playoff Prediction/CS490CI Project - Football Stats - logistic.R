# Load in csv data.
setwd("D:/Downloads") # Replace with dir where csv is stored.

# Import the csv file which contains headers
data = read.csv(file="CS490CI Project - Football StatsBIN.csv", head=TRUE, sep="," )

# load the required libraries
library(boot)
library(leaps)

# set a random seed so results can be reproduced
set.seed(1)

# this will be the number of models generated
iters=50

# create lists to store the results
cv.cv=rep(0,iters)
cv.error=rep(0,iters)
cv.cols=rep(list(),iters)

# generate the best subsets for the data
regfit.full=regsubsets(MadePlayoffs~.-Team,data=data,nvmax=25)

# generate the models
for (j in 1:iters)
{
	# create lists to store the data for each sub-model
	regfit.cv=rep(0,20)
	regfit.cols=rep(list(),20)

	# test a model of each size that best subsets produced a columns list for up to 20 predictors
	for ( i in 1:20 )
	{
		# create the subset of the data to be used for this sub-model
		subset=data[ , match( c("MadePlayoffs",names(coef(regfit.full,i))[-1]), names(data) ) ]

		# fit the sub-model
		glm.fit=glm(MadePlayoffs~.,data=subset,family=binomial)

		# determine the cross-validation error for this sub-model
		regfit.cv[i]=cv.glm(subset,glm.fit,K=10)$delta[1]

		# save the list of column names
		regfit.cols[i]=list(names(subset))
	}
	# get the number of predictors in the model with the lowest cross-validation error
	cv.cv[j]=min((1:20)[regfit.cv==min(regfit.cv)])
	
	# save the column list and the error for this model
	cv.cols[j]=regfit.cols[cv.cv[j]]
	cv.error[j]=min(regfit.cv)
}
# plot the error vs the size of the model
plot(c(cv.cv,0), c(cv.error*100,0), xlab="Number of predictors selected", ylab="Percent error", main="Cross-Validation error for Logistic Regression")

# print the list of columns in each model
cv.cols