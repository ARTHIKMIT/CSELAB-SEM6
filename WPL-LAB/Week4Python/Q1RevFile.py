"""
1. Write a python program to reverse a content a file and store it in another file.
"""

with open("Week4Python/inp.txt") as file:
    content = file.read()
    print(file)
    print(type(file))

revContent = content[::-1]

with open("Week4Python/inp.txt", "w") as file:
    file.write(revContent)

print("Reversed.")