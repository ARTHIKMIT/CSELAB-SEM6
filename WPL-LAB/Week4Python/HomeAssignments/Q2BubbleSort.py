"""
2. Write a python program to implement bubble sort.
"""

arr = [1, 43, 3, 564, 64, 23, 4, 0]

for i in range(len(arr)-1):
    for j in range(i, len(arr)):
        if arr[i] > arr[j]:
            arr[i], arr[j] = arr[j], arr[i]

print("Sorted Array : ", arr)