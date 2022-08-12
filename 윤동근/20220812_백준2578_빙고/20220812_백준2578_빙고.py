def check(BINGO_LIST):
    cnt = 0
    cnt_d1 = 0
    cnt_d2 = 0
    for j in range(5):
        cnt_x, cnt_y = 0, 0
        for k in range(5):
            if BINGO_LIST[j * 5 + k] == 0:
                cnt_x += 1
            if BINGO_LIST[j + k * 5] == 0:
                cnt_y += 1
        if BINGO_LIST[j * 6] == 0:
            cnt_d1 += 1
        if BINGO_LIST[4 + j * 4] == 0:
            cnt_d2 += 1
        if cnt_x == 5:
            cnt += 1
        if cnt_y == 5:
            cnt += 1
        if cnt_d1 == 5:
            cnt += 1
        if cnt_d2 == 5:
            cnt += 1

    return cnt

BINGO_LIST = []
BINGO_ORDER = []
for i in range(5):
    BINGO_LIST += list(map(int, input().split()))
for i in range(5):
    BINGO_ORDER += list(map(int, input().split()))
nums = 0
for i in range(25):
    for j in range(25):
        if BINGO_LIST[j] == BINGO_ORDER[i]:
            BINGO_LIST[j] = 0
            break
    nums += 1
    cnt = check(BINGO_LIST)
    if cnt >= 3:
        break






