def short():
    used = [0]*(N+1)

    value = [1e9] * (N + 1)
    value[0] = 0

    for _ in range(N):
        idx = 0
        minV = 1e9
        for i in range(N+1):
            if not used[i]:
                if value[i] < minV:
                    minV = value[i]
                    idx = i
        used[idx] = 1
        for k in range(N+1):
            if not used[k]:
                value[k] = min(value[k],edge[idx][k])

    return sum(value)

T = int(input())
for tc in range(1,T+1):
    N, M = map(int,input().split())
    edge = [[1e9] * (N+1) for _ in range(N+1)]

    for _ in range(M):
        a,b,c = map(int,input().split())
        edge[a][b] = c
        edge[b][a] = c

    print(f'#{tc} {short()}')