# BFS 로 풀기
# 과정
# 1. 지역에서 높이 최대값 찾기 (값이 작아서 생략가능)
# 2. 높이를 하나씩 늘리면서 찾기
# 3. 인접한 곳이 방문을 안 했고, 높이가 설정 높이보다 크면 큐에 넣기
# 4. 다 방문해보고 // 큐가 빌 때마다 = 영역 끝남 // 더해줌
# 5. 영역 개수랑 현재 영역개수 최댓값 비교하기

def bfs(height):
    global ans
    cnt = 0
    que = []
    used = [[0] * N for _ in range(N)]
    for y in range(N):
        for x in range(N):
            if area[y][x] > height and used[y][x] == 0:
                que.append([y,x])
                used[y][x] = 1
                while len(que) != 0:
                    i,j = que.pop(0)
                    for k in range(4):
                        ny = i + dy[k]
                        nx = j + dx[k]
                        if ny < 0 or nx < 0 or ny >= N or nx >= N:
                            continue
                        if used[ny][nx]:
                            continue
                        if area[ny][nx] <= height:
                            continue
                        que.append([ny,nx])
                        used[ny][nx] = 1
                cnt += 1
    if ans < cnt:
        ans = cnt

N = int(input())
area = [list(map(int,input().split())) for _ in range(N)]
mxx = -1
dy = [1,0,-1,0]
dx = [0,1,0,-1]
for y in range(N):
    for x in range(N):
        if mxx < area[y][x]:
            mxx = area[y][x]
ans = -1
for i in range(0,mxx+1):
    bfs(i)

print(ans)