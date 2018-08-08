output <- read.csv("~/koodit/python/collatzSequence/output.csv", header=FALSE)
ggplot(output,aes(x=V1,y=V2)) + stat_density2d()

## python softan tuottamaa dataa tässä katellaan...

ggplot(output,aes(x=V1,y=V2)) + stat_density2d(colour = heat.colors(8326, alpha = 1))

kuva + theme_dark()

kuva + theme_dark() + xlab("Integer") + ylab("Iterations") + labs(title = "Kuumotuskuvaaja")
