import pandas as pd
from collections import Counter

# Read the data to a pandas dataframe
df = pd.read_csv('~/koodit/collatzSequence/calculations.csv', names = ['Int', 'Iter'])

# Get maximum value of the iterations column
df['Iter'].max()

# So, the longest path to 1 was 949, now find the integer that it belongs to
df.loc[df['Iter'] == 949]

# Alternative way to count using Counter (Success!)
resultListCounter = Counter(df['Iter'])

# TODO: Import resultListCounter to pandas dataframe
# TODO: Will probably have to sort them as well
# TODO: Create a histogram out of that