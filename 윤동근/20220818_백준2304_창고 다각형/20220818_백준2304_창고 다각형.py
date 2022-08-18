N = int(input())
H_LIST = [list(map(int, input().split())) for i in range(N)]
H_LIST.sort(key = lambda x: x[0])   # 위치 기준으로 정렬
H_MAX = max(H_LIST, key = lambda x: x[1])   # MAX높이인 기둥 찾기
H_LIST_USED_LEFT = []
H_LIST_USED_RIGHT = []
LOW = 0
AREA = 0
for i in range(N):
    if H_LIST[i] == H_MAX:  # 높이 MAX값인 기둥 위치 찾기
        MAX_INDEX = i
for i in range(0, MAX_INDEX):   # 왼쪽에서 오른쪽으로 가장 높은 기둥 향하여 이동
    if LOW <= H_LIST[i][1] <= H_MAX[1]:
        H_LIST_USED_LEFT.append(H_LIST[i])
        LOW = H_LIST[i][1]
H_LIST_USED_LEFT.append(H_MAX)  # H_MAX 값 넣어서 기준 만들어주기(계산 가능하게)
LOW = 0
for i in range(N-1, MAX_INDEX, -1): # 오른쪽에서 왼쪽으로 가장 높은 기둥 향하여 이동
    if LOW <= H_LIST[i][1] <= H_MAX[1]:
        H_LIST_USED_RIGHT.append(H_LIST[i])
        LOW = H_LIST[i][1]
H_LIST_USED_RIGHT.append(H_MAX)

for i in range(len(H_LIST_USED_LEFT)-1):
    AREA += H_LIST_USED_LEFT[i][1] * (H_LIST_USED_LEFT[i+1][0] - H_LIST_USED_LEFT[i][0])    # 앞에서 가장 높은쪽으로 넓이 더하기
for i in range(len(H_LIST_USED_RIGHT)-1):
    AREA -= H_LIST_USED_RIGHT[i][1] * (H_LIST_USED_RIGHT[i+1][0] - H_LIST_USED_RIGHT[i][0]) # 뒤에서 앞으로 넓이 더하기
AREA += H_MAX[1]    # 가장 높은 기둥의 넓이 더하기
print(AREA)