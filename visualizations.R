# Visualizing the calculations from collatzSequence.c or collatzSequence.py

# Import the relevant library (probably don't need the whole tidyverse, though)
library(tidyverse)
library(ggplot2)

# Write the csv-file in
output <- read.csv("~/koodit/collatzSequence/calculations.csv", header=FALSE)

# Plot out a graph
ggplot(output,aes(x=V1,y=V2)) + stat_density2d()


# Plot out a graph with nifty colours
kuva <- ggplot(output,aes(x=V1,y=V2)) + stat_density2d(colour = heat.colors(8326, alpha = 1))


# Use a theme with the plotted graph
kuva + theme_dark()

# Use a better styled theme with the plotted graph
kuva + theme_dark() + xlab("Integer") + ylab("Iterations") + labs(title = "Kuumotuskuvaaja")
