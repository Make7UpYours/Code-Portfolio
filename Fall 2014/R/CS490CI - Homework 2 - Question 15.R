# 15. This problem involves the Boston data set, which we saw in the lab for
# this chapter. We will now try to predict per capita crime rate using the other
# variables in this data set. In other words, per capita crime rate is the 
# response, and the other variables are the predictors.
library(MASS)
attach(Boston)
name = names(Boston)

# (a) For each predictor, fit a simple linear regression model to predict
# the response. Describe your results. In which of the models is there a 
# statistically significant association between the predictor and the response?
# Create some plots to back up your assertions.

# Predictor: Residential zone
zone.fit = lm(crim~zn)
summary(zone.fit)
plot(zn, crim, main = "Crime & Zone Scatterplot", xlab = "Residential Zone Proportion",
     ylab = "Crime Rate")
abline(zone.fit, col = "red", lwd = 2)

# Predictor: Industrial Zone
indus.fit = lm(crim~indus)
summary(indus.fit)
plot(indus, crim, main = "Crime Rate & Industrial Zone Scatterplot", xlab = "Industrial Zone Proportion",
     ylab = "Crime Rate")
abline(indus.fit, col = "red", lwd = 2)

# Predictor: Charles River
chas.fit = lm(crim~chas)
summary(chas.fit)
plot(chas, crim, main = "Crime Rate & Charles River Bound Scatterplot", 
     xlab = "Bounded by Charles River(1 = yes, 0 = no)",
     ylab = "Crime Rate")
abline(chas.fit, col = "red", lwd = 2)

# Predictor: Nitrogen Oxides
nox.fit = lm(crim~nox)
summary(nox.fit)
plot(nox, crim, main = "Crime Rate & Nitrogen Oxides Scatterplot", 
     xlab = "Nitrogen Oxides Concentration (parts per 10 million)",
     ylab = "Crime Rate")
abline(nox.fit, col = "red", lwd = 2)

# Predictor: Avg. Rooms
rm.fit = lm(crim~rm)
summary(rm.fit)
plot(rm, crim, main = "Crime Rate & Average Rooms Scatterplot", 
     xlab = "Average Rooms per Dwelling",
     ylab = "Crime Rate")
abline(rm.fit, col = "red", lwd = 2)

# Predictor: Age
age.fit = lm(crim~age)
summary(age.fit)
plot(age, crim, main = "Crime Rate & Age Scatterplot", 
     xlab = "Proportion of Owner-Occupied units built prior to 1940",
     ylab = "Crime Rate")
abline(age.fit, col = "red", lwd = 2)

# Predictor: Distance
dis.fit = lm(crim~dis)
summary(dis.fit)
plot(dis, crim, main = "Crime Rate & Distance Scatterplot", 
     xlab = "Mean Distance to Boston Employment Centres",
     ylab = "Crime Rate")
abline(dis.fit, col = "red", lwd = 2)

# Predictor: Radial Highways
rad.fit = lm(crim~rad)
summary(rad.fit)
plot(rad, crim, main = "Crime Rate & Radial Highways Scatterplot", 
     xlab = "Index of Accessibility to Radial Highways",
     ylab = "Crime Rate")
abline(rad.fit, col = "red", lwd = 2)

# Predictor: Tax
tax.fit = lm(crim~tax)
summary(tax.fit)
plot(tax, crim, main = "Crime Rate & Tax Scatterplot", 
     xlab = "Property-tax rate per $10,000",
     ylab = "Crime Rate")
abline(tax.fit, col = "red", lwd = 2)

# Predictor: Pupil-Teacher Ratio
ptratio.fit = lm(crim~ptratio)
summary(ptratio.fit)
plot(ptratio, crim, main = "Crime Rate & Pupil-Teacher Ratio Scatterplot", 
     xlab = "Pupil-Teacher Ratio",
     ylab = "Crime Rate")
abline(ptratio.fit, col = "red", lwd = 2)

# Predictor: Black Proportion
black.fit = lm(crim~black)
summary(black.fit)
plot(black, crim, main = "Crime Rate & Black Proportion Scatterplot", 
     xlab = "Black Proportion by Town",
     ylab = "Crime Rate")
abline(black.fit, col = "red", lwd = 2)

# Predictor: Lower Status Population
lstat.fit = lm(crim~lstat)
summary(lstat.fit)
plot(lstat, crim, main = "Crime Rate & Lower Status Scatterplot", 
     xlab = "Lower Status of the Population",
     ylab = "Crime Rate")
abline(lstat.fit, col = "red", lwd = 2)

# Predictor: Median Home Value
medv.fit = lm(crim~medv)
summary(medv.fit)
plot(medv, crim, main = "Crime Rate & Median Home Value Scatterplot", 
     xlab = "Median Value of Homes",
     ylab = "Crime Rate")
abline(medv.fit, col = "red", lwd = 2)


# (b) Fit a multiple regression model to predict the response using all of the predictors.
# Describe your results. For which predictors can we reject the null hypothesis H0 : βj = 0?

all.fit = lm(crim~., data = Boston)
summary(all.fit)

all2.fit = lm(crim~.-indus-chas-rm-age-tax, data = Boston)
summary(all2.fit)

# (c) How do your results from (a) compare to your results from (b)? Create a plot displaying
# the univariate regression coefficients from (a) on the x-axis, and the multiple regression
# coefficients from (b) on the y-axis. That is, each predictor is displayed as a single point
# in the plot. Its coefficient in a simple linear regression model is shown on the x-axis,
# and its coefficient estimate in the multiple linear regression model is shown on the y-axis.
y = c(0.044855, -0.063855, -0.749134, -10.313535, 0.430131, 0.001452, -0.987176, 0.588209,
      -0.003780, -0.271081, -0.007538, 0.126211, -0.198887)
x = c(-0.07393, 0.50978, -1.8928, 31.249, -2.684, 0.10779, -1.5509, 0.61791, 0.029742,
      1.1520, -0.036280, 0.54880, -0.36316)
plot(x, y, xlab="Regression coefficients", ylab="Multiple regression coefficients",
     main = "Regression Coefficient Scatterplot",
     pch = c("Zn","In","CR","Nox","Rm","Age","Dis","Rad","Tax","PT","B","L","MHV"))
plot(x, y, xlab="Regression coefficients", ylab="Multiple regression coefficients",
     main = "Regression Coefficient Scatterplot",
     pch = c("Zn","In","CR","Nox","Rm","Age","Dis","Rad","Tax","PT","B","L","MHV"),
     xlim=c(-2,1.25), ylim=c(-1.25,.75))

# (d) Is there evidence of non-linear association between any of the predictors and the response?
# To answer this question, for each predictor X, fit a model in the form:
# Y = β0 + β1^X + β2X^2 + β3X^3 + ε.

# Predictor: Residential Zoning
res2.fit = lm(crim~poly(zn,3))
summary(res2.fit)

# Predictor: Industrial Zoning
indus2.fit = lm(crim~poly(indus,3))
summary(indus2.fit)

# Predictor: Charles River
chas2.fit = lm(crim~poly(chas,3))
summary(chas2.fit)

# Predictor: Nitrogen Oxides
nox2.fit = lm(crim~poly(nox,3))
summary(nox2.fit)

# Predictor: Avg. Rooms
rm2.fit = lm(crim~poly(rm,3))
summary(rm2.fit)

# Predictor: Age
age2.fit = lm(crim~poly(age,3))
summary(age2.fit)

# Predictor: Distance
dis2.fit = lm(crim~poly(dis,3))
summary(dis2.fit)

# Predictor: Radial Highways
rad2.fit = lm(crim~poly(rad,3))
summary(rad2.fit)

# Predictor: Tax
tax2.fit = lm(crim~poly(tax,3))
summary(tax2.fit)

# Predictor: Pupil-Teach Ratio
ptratio2.fit = lm(crim~poly(ptratio,3))
summary(ptratio2.fit)

# Predictor: Black Proportion
black2.fit = lm(crim~poly(black,3))
summary(black2.fit)

# Predictor: Lower Status Percent
lstat2.fit = lm(crim~poly(lstat,3))
summary(lstat2.fit)

# Predictor: Median Home Value
medv2.fit = lm(crim~poly(medv,3))
summary(medv2.fit)