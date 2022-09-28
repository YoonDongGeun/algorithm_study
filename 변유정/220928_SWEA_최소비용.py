def moving():
    que = []
    used = [[0]*N for _ in range(N)]
    cost = [[0]*N for _ in range(N)]
    used[0][0] = 1
    que.append([0,0])
    while len(que) > 0:
        cy, cx = que.pop(0)
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if 0 <= ny < N and 0 <= nx < N: #범위내에 속하고
                temp = cost[cy][cx] + 1
                if height[ny][nx] > height[cy][cx]:
                    temp += height[ny][nx] - height[cy][cx]
                if used[ny][nx] == 0 or cost[ny][nx] > temp: #들리지 않았거나
                    used[ny][nx] = 1  #전에 들렸어도 합이 현재보다 적으면 넣기
                    cost[ny][nx] = temp
                    que.append([ny, nx])

    return cost[N-1][N-1]

T = int(input())
for tc in range(1,T+1):
    N = int(input())
    height = [list(map(int,input().split())) for _ in range(N)]
    dy = [1,0,-1,0]
    dx = [0,1,0,-1]
    print(f'#{tc} {moving()}')