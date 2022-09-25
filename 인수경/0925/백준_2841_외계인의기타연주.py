import sys

n, p = map(int, sys.stdin.readline().rstrip().split())
arr = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(n)]
line = [[] for _ in range(7)]
res = 0

for ar in arr:
    if len(line[ar[0]]) == 0:
        line[ar[0]].append(ar[1])
        res += 1
    else:
        tmp = line[ar[0]][-1]
        if tmp == ar[1]:
            continue
        elif tmp < ar[1]:
            line[ar[0]].append(ar[1])
            res += 1
        else:
            while True:
                line[ar[0]].pop()
                res += 1
                if len(line[ar[0]]) == 0:
                    line[ar[0]].append(ar[1])
                    res += 1
                    break
                else:
                    tmp = line[ar[0]][-1]
                    if tmp == ar[1]:
                        break
                    elif tmp < ar[1]:
                        line[ar[0]].append(ar[1])
                        res += 1
                        break

print(res)
