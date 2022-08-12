BINGO_LIST = []
BINGO_ORDER = []
ch=[0,0,0,0,0]
for i in range(5):
    BINGO_LIST += list(map(int, input().split()))
for i in range(5):
    BINGO_ORDER += list(map(int, input().split()))
nums = 0
for i in range(25): # 빙고 탐색
    for j in range(25):
        if BINGO_LIST[j] == BINGO_ORDER[i]:
            BINGO_LIST[j] = 0
            break
    cnt = 0 # 빙고 갯수
    
    for k in range(5):
        if BINGO_LIST[k * 5:k * 5 + 5] == ch:  # x방향 체크
            cnt += 1
        if BINGO_LIST[k:25:5] == ch:  # y방향 체크
            cnt += 1
    if BINGO_LIST[0:25:6] == ch:  # 대각선 체크
        cnt += 1
    if BINGO_LIST[4:21:4] == ch:  # 반대 대각선 체크
        cnt += 1
    nums += 1   # 탐색 횟 수
    if cnt >= 3:
        break
print(nums)






