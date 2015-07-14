# Finds the min computation value and returns the cost along with the
# breakpoint index.
FindMin <- function(i, j, mat, dimMat){
  temp = matrix(NA,1,j - i)
  k = i
  while(k < j){
    # Modify function based on a 1-index array.
    temp[k] = mat[i,k] + mat[k+1,j] + dimMat[i]*dimMat[k+1]*dimMat[j+1]
    k = k+1
  }
  x = which.min(temp)
  return(list(M = temp[x], p = x))
}

# Finds the top 5 computation cost and returns a list containing the top 5 costs,
# along with their breakpoints.
FindTop5 <- function(i, j, mat, dimMat){
  temp = matrix(NA,1,j - i)
  k = i
  while(k < j){
    # Modify function based on a 1-index array.
    temp[k] = mat[i,k] + mat[k+1,j] + dimMat[i]*dimMat[k+1]*dimMat[j+1]
    k = k+1
  }
  tempSort = sort(temp, decreasing=FALSE)
  # Obtain the optimal 5 computation costs.
  tempPValues = list()
  index = 1
  for(i in 1:5){
    x <- which(temp == tempSort[i])
    # Store the pValues for the top 5 costs.
    for(j in 1:length(x)){
      tempPValues[index] = x[j];
      index = index + 1
    }
  }
  pValues = unique(tempPValues)
  costs = list()
  top5pValues = list()
  for(i in 1:5){
    pValue = as.numeric(pValues[i])
    costs[i] <- temp[pValue]
    top5pValues[i] <- pValue
  }
  return(list(M=costs,p=top5pValues))
}

# Traverses down the pValue chain and returns the expression tree for the
# resulting chain. Works on some chain expressions but not all.
ExpressTree <- function(pValues, i, j){
  expIndex = 1;
  expression = list();
  initialpValue = as.numeric(pValues[i,j])
  breakValue = initialpValue
  matrixNums = list()
  numIndex = 1
  # Traverse across the chain.
  while(breakValue != 0){
    matrixNums[numIndex] = breakValue
    numIndex = numIndex + 1
    breakValue = as.numeric(pValues[1, breakValue])
    if(breakValue != 0){
      expression[expIndex] = "("
      expIndex = expIndex + 1
    }
  }
  expression[expIndex] = toString(matrixNums[length(matrixNums)])
  expIndex = expIndex + 1
  if(length(matrixNums) != 1){
    for(index in (length(matrixNums) - 1):1){
      expression[expIndex] = "*"
      expIndex = expIndex + 1
      expression[expIndex] = toString(matrixNums[index])
      expIndex = expIndex + 1
      expression[expIndex] = ")"
      expIndex = expIndex + 1
    }
  }
  
  expression[expIndex] = "*"
  expIndex = expIndex + 1
  matrixNums = list()
  numIndex = 1
  breakValue = initialpValue
  closeBraceCount = 0
  
  # Traverse down the chain.
  while(breakValue != 0){
    matrixNums[numIndex] = breakValue + 1
    numIndex = numIndex + 1
    breakValue = as.numeric(pValues[breakValue+1, j])
  }
  for(index in 1:(length(matrixNums) - 1)){
    expression[expIndex] = "("
    expIndex = expIndex + 1
    closeBraceCount = closeBraceCount + 1
    expression[expIndex] = toString(matrixNums[index])
    expIndex = expIndex + 1
    expression[expIndex] = "*"
    expIndex = expIndex + 1
  }
  expression[expIndex] = toString(matrixNums[length(matrixNums)])
  expIndex = expIndex + 1
  
  for(i in 1:closeBraceCount){
    expression[expIndex] = ")"
    expIndex = expIndex + 1
  }
  return(expression)
}

# Returns the depth and width of a tree expression
DepthAndWidth <- function(expression){
  count = 0
  leftCount = 0
  rightCount = 0
  width = 0
  closeFound = FALSE
  for(i in 1:length(expression)){
    if(expression[i] == ")"){
      closeFound = TRUE
      count = count + 1
    }else if(expression[i] == "(" && closeFound){
      closeFound = FALSE
      leftCount = count
      count = 0
    }else if(expression[i] == "*"){
      width = width + 1
    }
  }
  rightCount = count
  width = width + 2
  depth = max(rightCount, leftCount)
  return(list(w = width, d = depth))
}

# Store Data paths, must change file path to where the data file is stored.
paths = list(F100 = "D:/Google Drive Sync Folder/Save Folder/Comp Sci 404/Project/Test Data/MatrixChainF100.csv",
             B100 = "D:/Google Drive Sync Folder/Save Folder/Comp Sci 404/Project/Test Data/RandB100.csv",
             C100 = "D:/Google Drive Sync Folder/Save Folder/Comp Sci 404/Project/Test Data/RandC100.csv",
             D100 = "D:/Google Drive Sync Folder/Save Folder/Comp Sci 404/Project/Test Data/RandD100.csv",
             S100 = "D:/Google Drive Sync Folder/Save Folder/Comp Sci 404/Project/Test Data/RandS100.csv",
             S200 = "D:/Google Drive Sync Folder/Save Folder/Comp Sci 404/Project/Test Data/RandS200.csv",
             S300 = "D:/Google Drive Sync Folder/Save Folder/Comp Sci 404/Project/Test Data/RandS300.csv",
             T100 = "D:/Google Drive Sync Folder/Save Folder/Comp Sci 404/Project/Test Data/RandT100.csv",
             T100b = "D:/Google Drive Sync Folder/Save Folder/Comp Sci 404/Project/Test Data/RandT100b.csv")

# Store dimension infomation
dims <- read.csv(paths$B100, header=FALSE)
dims = data.matrix(dims) # Convert to proper format for data manipulation.

size = dim(dims)[2] - 1

pValues = matrix(NA,size,size) # Store P-Value information
chain = matrix(NA,size,size) # Store M-Value information

for(i in 1:dim(chain)[1]){
  chain[i,i] = 0
  pValues[i,i] = 0
}

# Calculate the matrix chain, except the last combination.
for(j in 1:(dim(chain)[1] - 2)){
  for(i in 1:(dim(chain)[1] - j)){
    r = FindMin(i, i+j, chain, dims)
    m = r$M
    chain[i,i+j] = r$M[1]
    pValues[i,i+j] = r$p
  }
}

# Return the top 5 possible execution trees.
lastIndex = dim(chain)[1]
top5 = FindTop5(1, lastIndex, chain, dims)
topCost = as.numeric(top5$M)
topBreakPoints = as.numeric(top5$p)

# Evaluate the express tree
for(i in 1:5){
  pValues[1,size] = topBreakPoints[i]
  # Run into issues. I am not sure how well R handles Recursion or if I have
  # a logical error
  tree = ExpressTree(pValues, 1, size)
  wd = DepthAndWidth(tree)
  # Print the expression trees.
  print(paste("Tree",i,":",toString(tree),sep=" "))
  print(paste("Width",":",toString(wd$w),sep=" "))
  print(paste("Depth",":",toString(wd$d),sep=" "))
}