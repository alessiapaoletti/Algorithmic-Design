library(ggplot2)
size <-as.numeric(unlist(read.csv("res.csv", header = TRUE, sep = " " , colClasses = c(NA, rep("NULL",11)))))
insertion <- as.numeric(unlist(read.csv("res.csv", header = TRUE, sep = " " ,colClasses = c("NULL", NA, rep("NULL",10)))))
insertionBad <- as.numeric(unlist(read.csv("res.csv", header = TRUE, sep = " " ,colClasses = c(rep("NULL",2), NA, rep("NULL",9)))))
insertionBest <- as.numeric(unlist(read.csv("res.csv", header = TRUE, sep = " " , colClasses = c(rep("NULL",3), NA, rep("NULL",8)))))
quick <- as.numeric(unlist(read.csv("res.csv", header = TRUE, sep = " " ,colClasses = c(rep("NULL",4),NA, rep("NULL",7)))))
quickBad <- as.numeric(unlist(read.csv("res.csv", header = TRUE, sep = " " ,colClasses = c(rep("NULL",5), NA, rep("NULL",6)))))
quickBest <- as.numeric(unlist(read.csv("res.csv", header = TRUE, sep = " " , colClasses = c(rep("NULL",6), NA,rep("NULL",5)))))
counting <- as.numeric(unlist(read.csv("res.csv", header = TRUE, sep = " " ,colClasses = c(rep("NULL",7),NA, rep("NULL",4)))))
radix <- as.numeric(unlist(read.csv("res.csv", header = TRUE, sep = " " ,colClasses = c(rep("NULL",8), NA, rep("NULL",3)))))
bucket <- as.numeric(unlist(read.csv("res.csv", header = TRUE, sep = " " , colClasses = c(rep("NULL",9), NA, rep("NULL",2)))))
heapmin <- as.numeric(unlist(read.csv("res.csv", header = TRUE, sep = " " , colClasses = c(rep("NULL",10), NA, rep("NULL",1)))))
heapmax <- as.numeric(unlist(read.csv("res.csv", header = TRUE, sep = " " , colClasses = c(rep("NULL",11), NA))))

                     

size_square <- size**2
size_log <- log(size, base = 10)

size_tot<- c(replicate(3,size))
times_insertion <- c(insertion,insertionBest,insertionBad)
Case <- c(replicate(5,"Average"),replicate(5,"Best"),replicate(5,"Worst"))
insertionData<-data.frame(size_tot,times_insertion,Case)

ggplot(data=insertionData,aes(x=size_tot, y=times_insertion, group = Case, colour = Case)) + geom_line() +geom_point() +
  xlab("Size of the problem") + ylab("Log Time") + ggtitle("Insertion Sort") +
  scale_y_continuous(trans="log10")

times_quick <- c(quick,quickBest,quickBad)
quickData <- data.frame(size_tot, times_quick, Case)
ggplot(data=quickData,aes(x=size_tot, y=times_quick, group = Case, colour = Case)) + geom_line() +geom_point() +
  xlab("Size of the problem") + ylab("Log Time") + ggtitle("QuickSort") +
  scale_y_continuous(trans="log10")

times_heap <- c(heapmin,heapmax)
Case <- c(replicate(5,"HeapMin"),replicate(5,"HeapMax"))
heapData <- data.frame(rep(size,2),times_heap, Case)
ggplot(data=heapData,aes(x=rep(size,2), y=times_heap, group = Case, colour = Case)) + geom_line() +geom_point() +
  xlab("Size of the problem") + ylab("Log Time") + ggtitle("HeapSort") +
  scale_y_continuous(trans="log10")


size_all <- c(replicate(6,size))
times <- c(heapmax,insertion, quick, counting, radix, bucket)
Algorithm <- c(replicate(5,"HeapSort"),replicate(5,"InsertionSort"),replicate(5,"QuickSort"), replicate(5,"CoutingSort"),replicate(5,"RadixSort"),replicate(5,"BucketSort"))
sorting <- data.frame(size_all, times, Algorithm)
ggplot(data=sorting,aes(x=size_all, y=times, group = Algorithm, colour = Algorithm)) + geom_line() +geom_point() +
  xlab("Size of the problem") + ylab("Log Time") + ggtitle("Sorting") +
  scale_y_continuous(trans="log10")

