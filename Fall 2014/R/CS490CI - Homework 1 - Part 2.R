library(MASS)
attach(Boston)
# d. Do any of the suburbs of Boston appear to have particulary high
# crime rates? Tax rates? Pupil-teacher ratios? Comment on the range of
# each predictor.
# Crime
summary(crim)
thirdQuartCrim = 3.677 # store the 3rd quartile value
crime = crim
highCrime = matrix(1:length(crime), length(crime),1)
for(i in 1:length(crime)){
  if(crime[i] > thirdQuartCrim){
    highCrime[i] = crime[i]
  }else{
    highCrime[i] = "?"
  }
}
# Tax
summary(tax)
thirdQuartTax = 660.0 # store the 3rd quartile value
taxes = tax
highTax = matrix(1:length(taxes), length(taxes),1)
for(i in 1:length(taxes)){
  if(taxes[i] > thirdQuartTax){
    highTax[i] = taxes[i]
  }else{
    highTax[i] = "?"
  }
}
# Pupil-teacher ratio
summary(ptratio)
thirdQuartPT = 20.20 # store the 3rd quartile value
PT = ptratio
highPT = matrix(1:length(PT), length(PT),1)
for(i in 1:length(PT)){
  if(PT[i] > thirdQuartPT){
    highPT[i] = PT[i]
  }else{
    highPT[i] = "?"
  }
}

# e. How many of the suburbs in this data set bound the Charles River?
charles = chas
boundCount = 0
for(i in 1:length(charles)){
  if(charles[i] == 1){
    boundCount = boundCount + 1
  }
}

# f. What is the median pupil-teacher ratio among the towns in this data
# set?
median(ptratio)

# g. Which suburb of Boston has lowest median value of owner-occupied
# homes? What are the values of the other predictors for that suburb,
# and how do those values compare to the overall ranges for those
# predictors? Comment on your findings.
boston = Boston
lowestMedian = min(medv)
medians = medv
index = -1
for(i in 1:length(medians)){
  if(medians[i] == lowestMedian){
    index = i
  }
}
# store this data row
data = boston[460,]
summary(Boston)

# h. In this data set, how many of the suburbs average more than seven
# rooms per dwelling? More than eight rooms per dwelling? Comment on the
# suburbs that average more than eight rooms per dwelling.
rooms = rm
moreThanSeven = matrix(1:length(rooms),length(rooms),1)
moreThanSevenCount = 0
for(i in 1:length(rooms)){
  if(rooms[i] > 7){
    moreThanSeven[i] = rooms[i]
    moreThanSevenCount = moreThanSevenCount + 1 
  }
  else{
    moreThanSeven[i] = "?"
  }
}
# 8 or more rooms.
moreThanEight = matrix(1:length(rooms),length(rooms),1)
moreThanEightCount = 0
for(i in 1:length(rooms)){
  if(rooms[i] > 8){
    moreThanEight[i] = rooms[i]
    moreThanEightCount = moreThanEightCount + 1
  }
  else{
    moreThanEight[i] = "?"
  }
}

# Store the modified results in a table.
results = matrix(c(highCrime, highTax, highPT, charles, moreThanSeven, moreThanEight),
                 506,6, dimnames = list(c(1:506),c("High Crime",
                                                   "High Tax Rate",
                                                   "High PT Ratio",
                                                   "Bound by Charles",
                                                   "Avg. 7 or More Rooms",
                                                   "Avg. 8 or More Rooms")))