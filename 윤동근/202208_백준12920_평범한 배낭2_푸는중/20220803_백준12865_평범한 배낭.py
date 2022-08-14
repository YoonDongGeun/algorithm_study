N, K =map(int,input().split()) # 물품수, 버티는 무게
WEIGHT_VALUE = [list(map(int,input().split())) for _ in range(N)] # [무게, 가치]
WEIGHT_VALUE.sort(key = lambda x : x[1])
ITEM_VALUE_LIST = [0 for i in range(K+1)]
for j in range(N):
    MAX_VALUE_LIST = ITEM_VALUE_LIST[:] # 얕은 복사 (MAX는 이전값들이 저장되어짐)
    for i in range(K+1):
        if WEIGHT_VALUE[j][0]<=i:
            if WEIGHT_VALUE[j][1]+MAX_VALUE_LIST[i-WEIGHT_VALUE[j][0]] > MAX_VALUE_LIST[i]: # 배낭 i 무게에서 물건(j) 무게만큼 뺏을때의 배낭 무게의 행복도(a라고 하자 a는 기존 i일때의 행복도에서 물건 무게 뺀만큼의 행복도)에서 물건(j)를 추가하면 무게는 i, 행복도는(a+j의 행복도).  
                ITEM_VALUE_LIST[i] = WEIGHT_VALUE[j][1]+MAX_VALUE_LIST[i-WEIGHT_VALUE[j][0]] # 지금의 i무게의 행복도를 바꿔준다.
                print(ITEM_VALUE_LIST)

print(ITEM_VALUE_LIST[-1])
