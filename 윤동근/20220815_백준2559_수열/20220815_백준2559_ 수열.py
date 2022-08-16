N, K = map(int,input().split()) # N = 온도 잰 일수, K = K일
N_LIST = list(map(int, input().split())) # 온도 리스트
SUM_N = sum(N_LIST[:K]) # 1일부터 K일까지 온도 합
MAX_SUM = SUM_N # 초기 MAX 값은 SUM_N 설정
for i in range(N-K):
    SUM_N += N_LIST[i+K] - N_LIST[i] # 총 합에서 가장 앞의일 뺴고 마지막 다음일 추가.
    MAX_SUM = max(MAX_SUM, SUM_N) # 더 큰 값 반환.
print(MAX_SUM)
