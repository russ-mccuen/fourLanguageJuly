## Problem:

You're given a list of words sorted according to an alien dictionary. Your task is to determine the order of characters in the alien language.

## Input:

A list of words in lexicographical order according to an unknown alien language. For example:

words = ["wrt", "wrf", "er", "ett", "rftt"]

## Goal:

Return a string that represents the characters in the correct order. If the ordering is invalid (i.e. it’s impossible to determine), return an empty string.

## Complete Example From Above:

You're given that these words are sorted correctly by an alien dictionary. So, you can compare each adjacent pair of words to deduce relationships between characters:

    "wrt" vs "wrf" → 't' < 'f'

    "wrf" vs "er" → 'w' < 'e'

    "er" vs "ett" → 'r' < 't'

    "ett" vs "rftt" → 'e' < 'r'

From this, we learn that these are the directional edges for a graph:

    t → f

    w → e

    r → t

    e → r

Now we just need to topologically sort this graph to get a valid order of characters.

## Expected Output:

"wertf"
