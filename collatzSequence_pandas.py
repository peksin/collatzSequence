# Use this after creating a csv-file with collatzSequence_viz_noprint.py

import pandas as pd
import matplotlib.pyplot as plt
import os
import seaborn as sns


os.chdir('/home/pekka/koodit/python/collatzSequence/')

# Read the 'output.csv'

results = pd.read_csv('million.csv', header = None,
    names = ['Integer', 'Iterations'])

###########################################################

# Print a scatter plot with matplotlib

# plot = plt.scatter(results.Integer, results.Iterations,
#                    s = 0.01,
#                    color = "red")

# fig = plot.get_figure()
# fig.savefig('plot.png', dpi = 300)

###########################################################

# Print a scatter plot with seaborn
# And also set a nifty theme from seaborn
#
# sns.set_style("white")
# plot = sns.scatterplot(results.Integer, results.Iterations,
#                         s = 10,
#                         color = "blue",
#                         marker = ".")
#
#
# fig = plot.get_figure()
# fig.savefig('plot.png', dpi = 600)

############################################################

# Print a heatmap with pandas
