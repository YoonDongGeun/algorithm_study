T= int(input()) # 사람 수
N_LIST = list(map(int, input().split())) # 뽑은 번호 리스트
R_LIST = [] # 줄 서는 리스트
for i, j in enumerate(N_LIST): # i, j 로 사람마다 뽑은 번호 구별
    R_LIST[j:j]=[i+1]
print(*R_LIST[::-1]) # 거꾸로 돌리기.