N = int(input())                                              # NxN 행렬
house = [list(map(int, input().split())) for i in range(N)]   # 행렬 받아오기
DP = [[[0, 0, 0] for i in range(N)] for j in range(N)]        # DP i,j에 올수 있는 관 종류의 수량
DP[0][1][2] = 1
for i in range(N):
    for j in range(2, N):
        if house[i][j] == 0:
            if i < 1:                           # 가장 윗열은 왼쪽에서 오른쪽으로 가는 관만 받기 가능
                DP[i][j][2] += DP[i][j-1][2]
            else:
                if house[i][j-1] == 0 and house[i-1][j] == 0:   # 아랫 열은 위, 왼쪽, 대각선 성분에 따라 관 받을수 있는 것 다름.
                    DP[i][j][1] += DP[i - 1][j - 1][1] + DP[i-1][j - 1][2] + DP[i - 1][j-1][0]
                DP[i][j][0] += DP[i-1][j][0] + DP[i-1][j][1]
                DP[i][j][2] += DP[i][j-1][2] + DP[i][j-1][1]
print(sum(DP[N-1][N-1]))