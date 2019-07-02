size <- seq(1,15,1)
opt_sol <- c(0.001246,0.135597,0.184104,0.373841,0.550338,0.764883,1.543901,2.298726,2.335087,2.596672,3.123337,3.139957,3.020150,3.341258,3.791403)
naive_sol <- c(0.001263,0.132112,0.183977,0.370282,1.384745,2.374827,3.300034,3.658155,3.963235,4.439629,4.857078,5.256708,5.451080,5.855260,6.781664) 
plot(size,opt_sol,type="l",ylim = c(0,6.781664), col = "green", xlab = "Matrix Size", ylab = " Time")
points(size,naive_sol,type="l", col = "red")
legend("topleft", legend=c("Optimal Sol", "Naive Sol"),
       col=c("green", "red"), lty=1:1, cex=0.8)
