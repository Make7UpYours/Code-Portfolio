library(MASS)
library(splines)
attach(Boston)

dislims=range(dis)
dis.grid=seq(from=dislims[1],to=dislims[2])

# (b) Plot the polynomial fits for a range of different polynomial
# degrees (say, from 1 to 10), and report the associated residual
# sum of squares.
fit.1=lm(nox~dis,data=Boston)
fit.2=lm(nox~poly(dis,2),data=Boston)
fit.3=lm(nox~poly(dis,3),data=Boston)
fit.4=lm(nox~poly(dis,4),data=Boston)
fit.5=lm(nox~poly(dis,5),data=Boston)
fit.6=lm(nox~poly(dis,6),data=Boston)
fit.7=lm(nox~poly(dis,7),data=Boston)
fit.8=lm(nox~poly(dis,8),data=Boston)
fit.9=lm(nox~poly(dis,9),data=Boston)
fit.10=lm(nox~poly(dis,10),data=Boston)

pred1=predict(fit.1,newdata=list(dis=dis.grid),se=T)
pred2=predict(fit.2,newdata=list(dis=dis.grid),se=T)
pred3=predict(fit.3,newdata=list(dis=dis.grid),se=T)
pred4=predict(fit.4,newdata=list(dis=dis.grid),se=T)
pred5=predict(fit.5,newdata=list(dis=dis.grid),se=T)
pred6=predict(fit.6,newdata=list(dis=dis.grid),se=T)
pred7=predict(fit.7,newdata=list(dis=dis.grid),se=T)
pred8=predict(fit.8,newdata=list(dis=dis.grid),se=T)
pred9=predict(fit.9,newdata=list(dis=dis.grid),se=T)
pred10=predict(fit.10,newdata=list(dis=dis.grid),se=T)

plot(dis,nox,col="grey")
lines(dis.grid,pred1$fit,lwd=2,col=1)
lines(dis.grid,pred2$fit,lwd=2,col=2)
lines(dis.grid,pred3$fit,lwd=2,col=3)
lines(dis.grid,pred4$fit,lwd=2,col=4)
lines(dis.grid,pred5$fit,lwd=2,col=5)
title("Nox vs. Dis Poly 1-5 Plot")
legend(11,0.85,c("1","2","3","4","5"),lty=c(1,1,1,1,1),lwd=c(2,2,2,2,2),
       col=c(1,2,3,4,5))

plot(dis,nox,col="grey")
lines(dis.grid,pred6$fit,lwd=2,col=1)
lines(dis.grid,pred7$fit,lwd=2,col=2)
lines(dis.grid,pred8$fit,lwd=2,col=3)
lines(dis.grid,pred9$fit,lwd=2,col=4)
lines(dis.grid,pred10$fit,lwd=2,col=5)
title("Nox vs. Dis Poly 6-10 Plot")
legend(11,0.85,c("6","7","8","9","10"),lty=c(1,1,1,1,1),lwd=c(2,2,2,2,2),
       col=c(1,2,3,4,5))

anova(fit.1,fit.2,fit.3,fit.4,fit.5,fit.6,fit.7,fit.8,fit.9,fit.10)

# (e) Now fit a regression spline for a range of degrees of freedom,
# and plot the resulting fits and report the resulting RSS. Describe
# the results obtained.
sfit.3=lm(nox~bs(dis,df=3),data=Boston)
sfit.4=lm(nox~bs(dis,df=4),data=Boston)
sfit.5=lm(nox~bs(dis,df=5),data=Boston)
sfit.6=lm(nox~bs(dis,df=6),data=Boston)
sfit.7=lm(nox~bs(dis,df=7),data=Boston)
sfit.8=lm(nox~bs(dis,df=8),data=Boston)
sfit.9=lm(nox~bs(dis,df=9),data=Boston)
sfit.10=lm(nox~bs(dis,df=10),data=Boston)
sfit.11=lm(nox~bs(dis,df=11),data=Boston)
sfit.12=lm(nox~bs(dis,df=12),data=Boston)
sfit.13=lm(nox~bs(dis,df=13),data=Boston)
sfit.14=lm(nox~bs(dis,df=14),data=Boston)

pred.3=predict(sfit.3,newdata=list(dis=dis.grid),se=T)
pred.4=predict(sfit.4,newdata=list(dis=dis.grid),se=T)
pred.5=predict(sfit.5,newdata=list(dis=dis.grid),se=T)
pred.6=predict(sfit.6,newdata=list(dis=dis.grid),se=T)
pred.7=predict(sfit.7,newdata=list(dis=dis.grid),se=T)
pred.8=predict(sfit.8,newdata=list(dis=dis.grid),se=T)
pred.9=predict(sfit.9,newdata=list(dis=dis.grid),se=T)
pred.10=predict(sfit.10,newdata=list(dis=dis.grid),se=T)
pred.11=predict(sfit.11,newdata=list(dis=dis.grid),se=T)
pred.12=predict(sfit.12,newdata=list(dis=dis.grid),se=T)
pred.13=predict(sfit.13,newdata=list(dis=dis.grid),se=T)
pred.14=predict(sfit.14,newdata=list(dis=dis.grid),se=T)

plot(dis,nox,col="grey")
lines(dis.grid,pred.3$fit,lwd=2,col=1)
lines(dis.grid,pred.4$fit,lwd=2,col=2)
lines(dis.grid,pred.5$fit,lwd=2,col=3)
lines(dis.grid,pred.6$fit,lwd=2,col=4)
lines(dis.grid,pred.7$fit,lwd=2,col=5)
lines(dis.grid,pred.8$fit,lwd=2,col=6)
title("Nox vs. Dis Spline 3-8 Plot")
legend(11,0.85,c("3","4","5","6","7","8"),lty=c(1,1,1,1,1,1),lwd=c(2,2,2,2,2,2),
       col=c(1,2,3,4,5,6))

plot(dis,nox,col="grey")
lines(dis.grid,pred.9$fit,lwd=2,col=1)
lines(dis.grid,pred.10$fit,lwd=2,col=2)
lines(dis.grid,pred.11$fit,lwd=2,col=3)
lines(dis.grid,pred.12$fit,lwd=2,col=4)
lines(dis.grid,pred.13$fit,lwd=2,col=5)
lines(dis.grid,pred.14$fit,lwd=2,col=6)
title("Nox vs. Dis Spline 9-14 Plot")
legend(11,0.85,c("9","10","11","12","13","14"),lty=c(1,1,1,1,1,1),lwd=c(2,2,2,2,2,2),
       col=c(1,2,3,4,5,6))

anova(sfit.3,sfit.4,sfit.5,sfit.6,sfit.7,sfit.8,sfit.9,sfit.10,sfit.11,sfit.12,sfit.13,sfit.14)