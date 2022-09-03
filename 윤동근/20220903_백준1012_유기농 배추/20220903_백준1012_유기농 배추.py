def BFS1():  # 좌표 그대로 활용하는 방법
    cnt = 0
    while farm:
        cnt += 1
        Q = [farm.pop()]
        while Q:
            x, y = Q.pop(0)
            if [x+1, y] in farm:
                Q.append([x+1, y])
                farm.remove([x+1, y])
            if [x, y+1] in farm:
                Q.append([x, y+1])
                farm.remove([x, y+1])
            if [x-1, y] in farm:
                Q.append([x-1, y])
                farm.remove([x-1, y])
            if [x, y-1] in farm:
                Q.append([x, y-1])
                farm.remove([x, y-1])
    return cnt

def BFS2(y, x): # 그래프화 해서 BFS하는 방법
    Q = [[x, y]]
    while Q:
        x, y = Q.pop(0)
        if x+1 < M and F[y][x+1] == 1:
            Q.append([x + 1, y])
            F[y][x + 1] = 0
        if y+1 < N and F[y+1][x] == 1:
            Q.append([x, y + 1])
            F[y+1][x] = 0
        if 0 <= x-1 and F[y][x-1] == 1:
            Q.append([x - 1, y])
            F[y][x-1] = 0
        if 0 <= y-1 and F[y-1][x] == 1:
            Q.append([x, y - 1])
            F[y-1][x] = 0




T = int(input())
for _ in range(T):
    M, N, K = map(int, input().split())
    farm = [ list(map(int, input().split())) for i in range(K)]
    F = [[0] * M for i in range(N)]
    cnt = 0
    for x, y in farm:
        F[y][x] = 1
    for i in range(N):              # y
        for j in range(M):          # x
            if F[i][j] == 1:
                cnt += 1
                F[i][j] = 0
                BFS2(i, j)
    print(cnt)
