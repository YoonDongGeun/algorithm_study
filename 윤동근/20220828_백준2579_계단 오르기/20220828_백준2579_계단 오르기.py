N = int(input())                # 계단 수
st = []                         # 계단 담을 리스트
for i in range(N):
    st.append(int(input()))     # 계단마다 숫자 담기
DP = [[0, 0] for i in range(N)] # 계단 수만큼 담기
DP[0][0] = st[0]                # DP 0번째 인덱스는 st의 0번째 인덱스값 넣기.
DP[0][1] = st[0]
if N >= 2:                      # 이렇게 조건을 넣어줘야 index 에러가 안난다(ex 계단 1칸)
    DP[1][0] = DP[0][0] + st[1]
    DP[1][1] = st[1]
    for i in range(2, N):
        DP[i][0] = DP[i-1][1] + st[i]   # 뒤에 index가 0 이면 바로 앞에서 1칸 올라가는 경우를 저장하고
        DP[i][1] = max(DP[i-2]) + st[i] # 뒤에 index가 1 이면 2칸 뒤에서 올라오는 경우를 저장한다. 이때, 뒤에 2칸 올라오는 경우의 max값을 사용한다.
print(max(DP[-1]))                      # DP 마지막 도착지점에서 max값 받기.