"""
2. Write a python program to implement binary search with recursion.
"""

arr = [1, 3 ,5, 7, 33, 54]

def binSearch(l, u, data):
    if l > u:
        return -1
    
    m = (l+u) //2
    if data < arr[m]:
        return binSearch(l, m-1, data)
    elif data > arr[m]:
        return binSearch(m+1, u, data)
    else :
        return m
    
ind = binSearch(0, len(arr), 54)
print(ind)