N = int(input())
DICE = [list(map(int,input().split())) for i in range(N)]
N_max = 0
for i in range(6):
    sum = 0
    pick_1 = DICE[0][i]
    if i == 0:
        pick_2 =DICE[0][5]
        sum += max(DICE[0][1:5])
    elif i == 5:
        pick_2 = DICE[0][0]
        sum += max(DICE[0][1:5])
    elif i==3 or i==4:
        pick_2 = DICE[0][i-2]
        sum += max(DICE[0][:i-2]+[DICE[0][i-1]]+DICE[0][i+1:])
    else:
        pick_2 = DICE[0][i+2]
        sum += max(DICE[0][:i]+[DICE[0][i+1]]+DICE[0][i+3:])

    for j in range(1,N):
        for k in range(6):
            if DICE[j][k] == pick_2:
                pick_1 = pick_2
                if k == 0:
                    pick_2 = DICE[j][5]
                    sum += max(DICE[j][1:5])
                elif k == 5:
                    pick_2 = DICE[j][0]
                    sum += max(DICE[j][1:5])
                elif k == 3 or k==4:
                    pick_2 = DICE[j][k-2]
                    sum += max(DICE[j][:k-2]+[DICE[j][k-1]]+DICE[j][k+1:])
                else:
                    pick_2 = DICE[j][k+2]
                    sum += max(DICE[j][:k]+[DICE[j][k+1]]+DICE[j][k+3:])
                break
    if N_max < sum:
        N_max = sum
print(N_max)