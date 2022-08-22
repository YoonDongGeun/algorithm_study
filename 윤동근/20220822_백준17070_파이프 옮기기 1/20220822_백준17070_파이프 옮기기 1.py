def go(y=0, x=1, case=1):               # N,N으로 향하는 함수
    global cnt
    if y == x == N - 1:
        cnt += 1
        return
    if case == 1:                       # case = 1 이면 현재 ->방향 파이프 (오른쪽, 대각선만 연결가능)
        if x+1 < N-1:
            if house[y][x + 1] != 1:
                go(y, x + 1, 1)          # 오른쪽 움직이기 가능하면 case1
                if house[y + 1][x] != 1 and house[y + 1][x + 1] != 1:
                    go(y + 1, x + 1, 3)  # 대각선 움직일 수 있으면 case 3
        else:
            if y == N-1:
                if house[y][x + 1] != 1:
                    go(y, x + 1, 1)
                    return
            elif house[y][x + 1] != 1 and house[y + 1][x] != 1 and house[y + 1][x + 1] != 1:
                go(y + 1, x + 1, 3)
    elif case == 2:                      # case = 2 이면 현재 아래 방향 파이프 (아래, 대각선만 연결가능)
        if y + 1 < N - 1:
            if house[y + 1][x] != 1:
                go(y + 1, x, 2)
                if house[y][x + 1] != 1 and house[y + 1][x + 1] != 1:
                    go(y + 1, x + 1, 3)
            return
        else:
            if x == N-1:
                if house[y + 1][x] != 1:
                    go(y+1, x, 2)
                    return
            if house[y + 1][x] != 1 and house[y][x + 1] != 1 and house[y + 1][x + 1] != 1:
                go(y + 1, x + 1, 3)
    else:                                # case = 3 이면 현재 대각선 파이프 (모두 연결가능)
        if y == N-1:                     # y값이 가장 아래에있으면
            if house[y][x + 1] != 1:
                go(y, x + 1, 1)
                return
        elif x == N-1:                   # x값이 가장 오른쪽에 있으면
            if house[y + 1][x] != 1:
                go(y + 1, x, 2)
                return
        else:
            if house[y][x + 1] != 1:
                if x+1 < N-1:
                    go(y, x + 1, 1)
                if house[y + 1][x] != 1 and house[y + 1][x + 1] != 1:
                    go(y + 1, x + 1, 3)
            if house[y + 1][x] != 1:
                if y + 1 != N - 1:
                    go(y + 1, x, 2)

N = int(input())                                                    # NxN 행렬
house = [list(map(int, input().split())) + [1] for i in range(N)]   # 행렬 받아오기 (쉽게 하기 위해 벽([1])추가)
house.append([1] * (N + 1))                                         # 맨 밑에 행에 벽 [1] 추가
cnt = 0                                                             # N,N에 도달한 횟수
go(0, 1, 1)
print(cnt)