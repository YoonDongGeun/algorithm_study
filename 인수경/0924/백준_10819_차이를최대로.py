def perm(k, n):
    if k == n:
        sumV = 0
        for i in range(n-1):
            sumV += abs(p[i]-p[i+1])
        res.append(sumV)
    else:
        for i in range(n):
            if used[i] == 0:
                p[k] = arr[i]
                used[i] = 1
                perm(k+1, n)
                used[i] = 0


n = int(input())
arr = list(map(int, input().split()))
p = [0] * n
used = [0] * n
res = []
perm(0, n)
print(max(res))
