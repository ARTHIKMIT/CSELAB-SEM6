"""
3. Write a python program to sort words in alphabetical order.
"""


sentence = "hi this is a weird sentence ok apple"

words = sentence.split(" ")
out = " ".join(sorted(words, key=str.lower))
print(out)