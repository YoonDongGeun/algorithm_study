N = int(input())
NUM = list(map(int, input().split()))
cnt_max = 1     # cnt의 최대값
cnt_up = 1      # 올라가는 숫자의 최대 길이 값
cnt_down = 1    # 내려가는 숫자의 최대 길이 값
for i in range(N-1):
    if NUM[i] < NUM[i+1]:       # 숫자가 올라가면
        cnt_up += 1             # 올라가는 값 +1
        cnt_down = 1            # 내려가는 값 초기화
    elif NUM[i] > NUM[i+1]:     # 숫자가 내려가면
        cnt_down += 1           # 위와 같은 방식
        cnt_up = 1
    else:                       # 숫자가 동일하면 둘다 +1
        cnt_up += 1
        cnt_down += 1
    cnt_max = max(cnt_up, cnt_down, cnt_max)    # max값 반환
print(cnt_max)