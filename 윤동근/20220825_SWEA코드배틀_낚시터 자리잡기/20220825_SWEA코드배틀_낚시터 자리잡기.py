def batch(G, P):                # 0번 인덱스 쪽 우선으로 넣고 오른쪽 인덱스 번갈아가며 넣기.
    cnt, i, sum_ = 0, 0, 0
    while i != P:
        if (0 <= G+gate_[i+cnt] < N) and (fish[G+gate_[i+cnt]] == 0):
            fish[G+gate_[i+cnt]] += 1
            sum_ += abs(gate_[i+cnt])+1
            i += 1
        else:
            cnt += 1
    return sum_

def batch2(G, P):               # 마지막 인덱스쪽 우선 배치, 0번 인덱스 번갈아 가며 배치
    cnt, i, sum_ = 0, 0, 0
    while i != P:
        if (0 <= G-gate_[i+cnt] < N) and (fish[G-gate_[i+cnt]] == 0):
            fish[G-gate_[i+cnt]] += 1
            sum_ += abs(gate_[i + cnt])+1
            i += 1
        else:
            cnt += 1
    return sum_

def per(w, GPx):                # 3개짜리 집합의 모든 순열 GPs에 추가
    GP = GPx[:]
    if w == 2:
        GPs.append(GP)
        return
    for i in range(w,3):
        GP[w], GP[i] = GP[i], GP[w]
        per(w+1, GP)
        GP[w], GP[i] = GP[i], GP[w]
def brute_force(GP1, GP2, GP3):    # 모든 방법에 대해 탐색
    global min_
    global fish
    cnt = 0

    while cnt != 4:
        sum_ = 0
        sum_ += batch(GP1[0], GP1[1]) if cnt < 1 else batch2(GP1[0], GP1[1])
        sum_ += batch(GP2[0], GP2[1]) if cnt < 2 else batch2(GP2[0], GP2[1])
        sum_ += batch(GP3[0], GP3[1]) if cnt < 3 else batch2(GP3[0], GP3[1])
        fish = [0] * N
        if min_ > sum_:
            min_ = sum_
        cnt +=1

T = int(input())
for _ in range(1, T+1):
    N = int(input())
    gates = []
    G_LIST = [list(map(int, input().split())) for i in range(3)]
    for i in range(3):
        G_LIST[i][0] -= 1
    fish = [0] * N
    gate_ = []
    for i in range(200):                # 게이트에서 낚시꾼 배치시키는 순서.
        if i % 2 == 0:
            gate_.append(i // 2)
        else:
            gate_.append(-i // 2)

    min_ = 100000                       # min_값은
    GP = [i for i in G_LIST]            # GP의 게이트 1, 2, 3 의 위치와 그곳 의 사람수 가져오기 (위치, 사람수), (위치2, 사람수2)...
    GPs = []
    per(0, GP)                          # GPs에 GP의 모든 순서 조합에 대해 추가하는 함수 per
    for GP1, GP2, GP3 in GPs:
        brute_force(GP1, GP2, GP3)      # 이 순열에서 모든 경우에 대해 탐색
    print(f'#{_} {min_}')
