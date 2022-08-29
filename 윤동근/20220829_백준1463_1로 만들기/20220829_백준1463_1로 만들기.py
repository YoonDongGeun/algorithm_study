N = int(input())
dp = [N] * (N+1)
dp[-1] = 0
for i in range(N,0,-1):
    if i%3 == 0:                            # 맨 끝(N)에서 부터 3나눌때 그 값까지 더 적은 과정 저장.
        dp[i//3] = min(dp[i]+1, dp[i//3])
    if i%2 == 0:
        dp[i//2] = min(dp[i]+1, dp[i//2])
    dp[i-1] = min(dp[i]+1, dp[i-1])
print(dp[1])