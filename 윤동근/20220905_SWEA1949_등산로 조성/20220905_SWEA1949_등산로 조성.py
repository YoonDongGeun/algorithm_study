dM= [(0, 1), (0, -1), (1, 0), (-1, 0)] # 상하좌우 탐색용

def search(y, x, S):                   # x,y에 도착한뒤 상하좌우 search
    global cnt, max_cnt
    cnt += 1                           # 경로 1개당 +1
    visited[y][x] = 1
    if max_cnt < cnt:                  # 가장 경로 길때 반환
        max_cnt = cnt
    for dy, dx in dM:
        ny = y + dy
        nx = x + dx
        if 0 <= ny < N and 0 <= nx < N and visited[ny][nx] == 0:    # ny, nx가 인덱스 범위안에 들어오고, visited 한적 없을때 실시.
            if M[ny][nx] >= M[y][x]:                                # 만약 search해야하는 곳이 기존 위치보다 높다면 깎을 수 있나 확인.
                if S == 0 and M[ny][nx]-K < M[y][x]:                # 깎기 가능하면 (현재 높이의-1) 로 그 위치 깎기.
                    tm = M[ny][nx]
                    M[ny][nx] = M[y][x]-1
                    search(ny, nx, 1)                               # 그 위치 탐색
                    M[ny][nx] = tm
                else:
                    continue
            else:
                search(ny, nx, S)                                   # 만약 더 낮다면 그 위치 탐색.

    visited[y][x] = 0                   # 탐색 끝나면 다시 visited 원상 복구
    cnt -= 1                            # 끝나면 -1


T = int(input())
for _ in range(1, T+1):
    N, K = map(int, input().split())
    M = []
    visited = [[0] * N for i in range(N)]
    temp = list(map(int, input().split()))
    M_H = max(temp)
    M.append(temp)
    M_H_L = []
    for i in range(N-1):
        temp = list(map(int,input().split()))
        M.append(temp)
        for k in temp:
            if k > M_H:
                M_H = k                 # 가장 높은 꼭대기 높이값 찾기.
    cnt = 0
    max_cnt = 0
    for i in range(N):
        for j in range(N):
            if M[i][j] == M_H:          # 꼭대기인 곳 리시트 M_H_L에 저장.
                M_H_L.append((i,j))
    for y,x in M_H_L:                       # 모든 꼭대기에 대해서 탐색.
        search(y,x,0)
    print(f'#{_} {max_cnt}')
