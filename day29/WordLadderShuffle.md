## Word Ladder Shuffle  

You're given two words of the same length and a dictionary of valid words. Transform the start word into the end word by changing only one letter at a time, with each intermediate word being a valid word from the dictionary.

Return the shortest sequence of words showing the transformation. If no such sequence exists, return an empty list.

Example:

start = "hit"  
end = "cog"  
dictionary = ["hot","dot","dog","lot","log","cog"]  

Output: ["hit", "hot", "dot", "dog", "cog"]

    "hit" → "hot" (change 'i' to 'o') — valid

    "hot" → "dot" (change 'h' to 'd') — valid

    "dot" → "dog" (change 't' to 'g') — valid

    "dog" → "cog" (change 'd' to 'c') — valid

Path found:

["hit", "hot", "dot", "dog", "cog"]
