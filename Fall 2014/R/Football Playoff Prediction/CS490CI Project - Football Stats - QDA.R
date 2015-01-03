# Load in csv data.
setwd("~/Desktop") # Replace with dir where csv is stored.

# Import the csv file which contains headers
data = read.csv(file="CS490CI Project - Football StatsBIN.csv", head=TRUE, sep="," )

dataPred = read.csv(file="football2014.csv", head=TRUE, sep="," )

# look for relevant features building scatterplots
pairs(data[,-2]) # remove MadePlayoffs

# exclude data point with little to no linear relation
newdata <- data[c(-1,-4,-7,-11,-15,-18,-27)]

# look for relevant feature with newdata
pairs(newdata[,-1]) # remove MadePlayoffs 

# exclude more data points
newdata <- newdata[c(-6,-7,-17,-18)]

# again look for relevant features
pairs(newdata[,-1]) # remove MadePlayoffs

# removing "rushing" variable
# They have a strong linear relationship with each other but no other varialbes. 
newdata <- newdata[c(-13,-14,-15)]

# let's view the new scatterplot
pairs(newdata[,-1]) # removing MadePlayoffs

# removing three more features (wins, passing.completions, passing.attempts)
newdata <- newdata[c(-2,-7,-8)]

# yet again scatterplot the new data
pairs(newdata[,-1]) # removing MadePlayoffs

# split the data into test cases and train cases
train <- 1:300
train.X <- newdata[train,-1]
train.Y <- newdata[train,1]

test <- 301:352
test.X <- newdata[test,-1]
test.Y <- newdata[test,1]

# begin the QDA analysis
library(MASS) # contains qda function
fit <- qda(MadePlayoffs~PointsFor+TotalYards+Yards.Play+Total1stDowns+PassingYards+PassingTDs+NetYards.Attempt+Passing1stDowns+Scoring.,data=newdata)
pred <- predict(fit, test.X)
# Compare the prediction and the test case
pred$class
test.Y

# find the error rate
mean(pred$class!=test.Y)
# the test error rate is 13.46%




