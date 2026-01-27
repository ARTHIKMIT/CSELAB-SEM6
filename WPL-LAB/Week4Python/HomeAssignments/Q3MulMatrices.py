a = [[1, 2],
     [3, 4]]

b = [[1,2, 3],
     [4, 5, 6]]

m, n = len(a), len(a[0])
p, q = len(b), len(b[0])

if n != p:
    print("Incompatible Matrics")
    exit()

res = [[0]*q for _ in range(m)]
print(res)

for i in range(m):
    for j in range(q):
        res[i][j] = 0
        for k in range(n):
            res[i][j] += a[i][k] * b[k][j]

print("Result is : ", res)