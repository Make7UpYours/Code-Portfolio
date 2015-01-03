library(tree)
library(randomForest)

# Load in csv data.
setwd("Q:/Classes/CS490CI/Project") # Replace with dir where csv is stored.
data = read.csv("CS490CI Project - Football Stats.csv")
names(data)

# Split the sample into train and test sets.
set.seed(2)
train = sample(1:nrow(data), nrow(data)/2)
data.test = data[-train,]

playoffs.tree1 = tree(MadePlayoffs~.,data=data,subset=train)
plot(playoffs.tree1)
text(playoffs.tree1,pretty=0)
title("Playoff Tree - All Predictors") # Not a good model
# Calculating the confusion matrix and error
tree.pred1=predict(playoffs.tree1,data.test,type="class")
table(tree.pred1,data.test$MadePlayoffs)
(93+53)/176 # error is only correct if you run with the seed set.

playoffs.tree2 = tree(MadePlayoffs~.-Team,data=data,subset=train)
plot(playoffs.tree2)
text(playoffs.tree2,pretty=0)
title("Playoff Tree - Disregard Teams") # Wins are defentially a determining factor
# Calculating the confusion matrix and error
tree.pred2=predict(playoffs.tree2,data.test,type="class")
table(tree.pred2,data.test$MadePlayoffs)
(101+51)/176 # error is only correct if you run with the seed set.

playoffs.tree3 = tree(MadePlayoffs~.-Team-Wins-Year,data=data,subset=train)
plot(playoffs.tree3)
text(playoffs.tree3,pretty=0)
title("Playoff Tree - Disregard Wins,Team,Year\nError = 77.84%") # We get a larger tree with more predictors if we disregard wins
# Calculating the confusion matrix and error
tree.pred3=predict(playoffs.tree3,data.test,type="class")
table(tree.pred3,data.test$MadePlayoffs)
(91+46)/176 # error is only correct if you run with the seed set.

# Reducing predictors using CV
cv.playoffs=cv.tree(playoffs.tree3)
plot(cv.playoffs$size,cv.playoffs$dev,type="b")
# 6 predictors appear to be the best.

prune.playoffs=prune.tree(playoffs.tree3,best=6)
plot(prune.playoffs)
text(prune.playoffs,pretty=0)
title("Pruned Playoff Tree\nError = 76.70%")
# Calculating the confusion matrix and error
tree.pred4=predict(prune.playoffs,data.test,type="class")
table(tree.pred4,data.test$MadePlayoffs)
(84+51)/176

# Finding the important variables using random forests
rf.playoffs1=randomForest(MadePlayoffs~.,data=data,subset=train,
                           importance=TRUE)
rf.pred1=predict(rf.playoffs1,data.test,type="class")
table(rf.pred1,data.test$MadePlayoffs)
(107+50)/176
importance(rf.playoffs1)
varImpPlot(rf.playoffs1)

rf.playoffs2=randomForest(MadePlayoffs~.-Team-Wins-Year,data=data,subset=train,
                          importance=TRUE)
rf.pred2=predict(rf.playoffs2,data.test,type="class")
table(rf.pred2,data.test$MadePlayoffs)
(94+48)/176
importance(rf.playoffs2)
varImpPlot(rf.playoffs2,main="Variable Importance Plot")
