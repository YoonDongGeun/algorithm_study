n = int(input())                                            # 집 갯수
RGB = [list(map(int,input().split())) for _ in range(n)]    # 각각의 집 도색 가격
dp = [[] for _ in range(n)]                                 # 최적의 가격 저장
dp[0] = RGB[0]
for i in range(1, n):
    for j in range(3):
        dp[i].append(RGB[i][j] + min(dp[i-1][j-1], dp[i-1][j-2]))   # i에서 RGB 중 1개 골랐을때 i-1번째 에서 최소값
print(min(dp[-1]))
