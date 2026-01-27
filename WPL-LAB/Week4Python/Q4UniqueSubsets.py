"""
4. Write a Python class to get all possible unique subsets from a set of distinct
integers 
Input:[4,5,6]
Output : [[], [6], [5], [5, 6], [4], [4, 6], [4, 5], [4, 5, 6]]
"""

from itertools import combinations

nums = [4, 5, 6]
out = []

for r in range(len(nums) + 1):
    out.extend(list(combinations(nums, r)))

print(out)



class Sol:
    def subsets(self, nums):
        out = []
        curr = []

        def bt (start):
            out.append(curr[:])
            for i in range(start, len(nums)):
                curr.append(nums[i])
                bt(i+1)
                curr.pop()
        bt(0)
        return out

print(Sol().subsets([4, 5, 6]))