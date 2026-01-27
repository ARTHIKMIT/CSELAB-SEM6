"""
5. Write a Python class to find a pair of elements (indices of the two numbers)
from a given array whose sum equals a specific target number.
Input: numbers= [10,20,10,40,50,60,70], target=50
Output: 3, 4
"""

nums = [10,20,10,40,50,60,70]
target = 50

for i in range(1, len(nums)):
    if nums[i-1] + nums[i] == target:
        print("Inds are : ", i, i-1)
        break