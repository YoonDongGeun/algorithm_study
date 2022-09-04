def go(Q):                      # Q 가 코어개수만큼 돼면 멈춘다.
    global cnt1, cnt2, core, line
    if Q == len(C):
        if cnt1 > core:
            core = cnt1
            line = cnt2
        elif cnt1 == core:
            if line > cnt2:
                line = cnt2     # 가장 많이 연결했을때 찾기.
        return
    y, x = C[Q][0], C[Q][1]     # y,x 의 좌표는 Q의 값에따라 순차적으로 1번코어~ len(C)번 코어

    for j in range(y):
        if M[j][x] != 0:        # 1가지 방향에 대해 연결 가능한지 탐색
            break
    else:
        cnt1 += 1               # 만약 연결 가능하면 코어 연결갯수 +1
        for k in range(y):
            # cnt2 += 1           #  1) 전선필요 갯수 +1
            M[k][x] = 1
        cnt2 += y                 #  2) 전선 필요 갯수 한번에 +하기
        go(Q+1)
        cnt1 -= 1
        cnt2 -= y
        for k in range(y):
            # cnt2 -= 1
            M[k][x] = 0

    for j in range(x + 1, N):   # 오른쪽 방향
        if M[y][j] != 0:
            break
    else:
        cnt1 += 1
        # for k in range(x + 1, N):
        #     # cnt2 += 1                 # 1)
        #     M[y][k] = 1
        M[y][x+1:] = [1] * (N-(x+1))
        cnt2 += N - (x+1)               # 2)
        go(Q + 1)
        cnt1 -= 1
        cnt2 -= N - (x+1)
        M[y][x + 1:] = [0] * (N - (x + 1))
        # for k in range(x + 1, N):
        #     # cnt2 -= 1
        #     M[y][k] = 0

    for j in range(y + 1, N):   # 아래 방향
        if M[j][x] != 0:
            break
    else:
        cnt1 += 1
        for k in range(y + 1, N):
            # cnt2 += 1                 # 1)
            M[k][x] = 1
        cnt2 += N-(y+1)                 # 2)
        go(Q+1)
        cnt1 -= 1
        cnt2 -= N-(y+1)
        for k in range(y + 1, N):
            # cnt2 -= 1
            M[k][x] = 0

    for j in range(x):           # 왼쪽 방향
        if M[y][j] != 0:
            break
    else:
        cnt1 += 1
        # for k in range(x):
        #     # cnt2 += 1                 # 1)
        #     M[y][k] = 1
        M[y][:x] = [1]*x
        cnt2 += x                     # 2)
        go(Q+1)
        cnt1 -= 1
        cnt2 -= x
        M[y][:x] = [0]*x
        # for k in range(x):
        #     # cnt2 -= 1
        #     M[y][k] = 0
    go(Q+1)                       # Q번 코어 연결 안하고 Q+1번쨰 코어 탐색할 때

T = int(input())
for _ in range(1, T+1):
    C = []                                      # 연결해야하는 코어 좌표 담기.
    M = []                                      # 전체 맵 담기
    N = int(input())
    for i in range(N):
        temp = list(map(int, input().split()))  # temp에 1줄씩 반도체판 맵 가져오기
        if i != 0 and i != N-1:
            for j in range(1, N-1):             # 모서리쪽에 없으면 코어 좌표 C에 추가.
                if temp[j] == 1:
                    C.append((i, j))
        M.append(temp)                          # C에 temp 1줄씩 담기.
    core = 0
    line = 2000
    cnt1 = 0
    cnt2 = 0
    go(0)
    print(f'#{_} {line}')

