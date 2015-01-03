# Function Definitions
# Function returns the square difference between two points.
diffSquare = function(y, yHat){
  diff = y - yHat
  return(diff^2)
}

# a. Create a random sample of 50 points drawn from a Gaussian
# distribution with mean=10 and variance=9.
set.seed(75)
Gauss = rnorm(50, 10, 3)

# b. Create a histogram of the sample.
hGauss <- hist(Gauss, freq=FALSE, xlim = c(0,20))

# c. Overlay the corresponding density function on your
# histogram.
x <- seq(0, 20, length=70)
lines(x, dnorm(x, 10, 3), col = "red")
y <-dnorm(x, 10, 3)

# d. Calculate the error between the density function and the
# histogram.
histVect <- hGauss[3]
total = 0
k = 1
# loop through the histVect values.
for(j in 1:7){
  l = k + 9
  # loop through the y-values of the normal curve.
  for(i in k:l){
    total = total + diffSquare(y[i], histVect[[1]][j])
  }
  k = k + 10
}

# Create a vector to store MSE & bin values.
MSE.mse = NULL
MSE.bin = NULL
MSE.mse[3] = total / 70
MSE.bin[3] = 2

# e. Repeat b & d for different histogram bin sizes, and plot
# a graph between bin size and magnitue of error.



# Use a 1/2 bin size
# Create a histogram of the sample with .5 bin size.
hGauss <- hist(Gauss, 40, freq=FALSE, xlim = c(0,20))

# Overlay the corresponding density function on your
# histogram.
x <- seq(0, 20, length=240)
lines(x, dnorm(x, 10, 3), col = "red")
y <-dnorm(x, 10, 3)

# d. Calculate the error between the density function and the
# histogram.
histVect <- hGauss[3]
total = 0
k = 1
# loop through the histVect values.
for(j in 1:24){
  l = k + 9
  # loop through the y-values of the normal curve.
  for(i in k:l){
    total = total + diffSquare(y[i], histVect[[1]][j])
  }
  k = k + 10
}
# add values to MSE
MSE.mse[1] = total / 240
MSE.bin[1] = .5


# Create a histogram of the sample with 1 bin size.
hGauss <- hist(Gauss, 15, freq=FALSE, xlim = c(0,20))

# Overlay the corresponding density function on your
# histogram.
x <- seq(0, 20, length=120)
lines(x, dnorm(x, 10, 3), col = "red")
y <-dnorm(x, 10, 3)

# d. Calculate the error between the density function and the
# histogram.
histVect <- hGauss[3]
total = 0
k = 1
# loop through the histVect values.
for(j in 1:12){
  l = k + 9
  # loop through the y-values of the normal curve.
  for(i in k:l){
    total = total + diffSquare(y[i], histVect[[1]][j])
  }
  k = k + 10
}
# add values to MSE
MSE.mse[2] = total / 120
MSE.bin[2] = 1



# Create a histogram of the sample with 5 bin size.
hGauss <- hist(Gauss, 4, freq=FALSE, ylim = c(0,.15), xlim = c(0,20))

# Overlay the corresponding density function on your
# histogram.
x <- seq(0, 20, length=30)
lines(x, dnorm(x, 10, 3), col = "red")
y <-dnorm(x, 10, 3)

# d. Calculate the error between the density function and the
# histogram.
histVect <- hGauss[3]
total = 0
k = 1
# loop through the histVect values.
for(j in 1:3){
  l = k + 9
  # loop through the y-values of the normal curve.
  for(i in k:l){
    total = total + diffSquare(y[i], histVect[[1]][j])
  }
  k = k + 10
}
# add values to MSE
MSE.mse[4] = total / 30
MSE.bin[4] = 5



# Create a histogram of the sample with 10 bin size.
hGauss <- hist(Gauss, 1, freq=FALSE, ylim=c(0, .15))

# Overlay the corresponding density function on your
# histogram.
x <- seq(0, 20, length=20)
lines(x, dnorm(x, 10, 3), col = "red")
y <-dnorm(x, 10, 3)

# d. Calculate the error between the density function and the
# histogram.
histVect <- hGauss[3]
total = 0
k = 1
# loop through the histVect values.
for(j in 1:2){
  l = k + 9
  # loop through the y-values of the normal curve.
  for(i in k:l){
    total = total + diffSquare(y[i], histVect[[1]][j])
  }
  k = k + 10
}
# add values to MSE
MSE.mse[5] = total / 20
MSE.bin[5] = 10


# plot the mse vs. bin size graph.
plot(MSE.bin, MSE.mse, "b", ylab = "MSE", xlab ="Bin Size", col = "red", main = "MSE of Varying Bin Sizes")