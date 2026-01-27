"""
1. Write a python program to select smallest element from a list in an expected
linear time.
"""

arr = [1, 4, 3 ,65, 2, -1]
s = 0

for i in range(1, len(arr)):
    if arr[s] > arr[i]:
        s = i

print("Smallest elemet is ", arr[s], " at index : ", s)