def make_S(SS, c):
    if c == SS_L:
        SK = SS[:]
        for j in range(0, SS_L, 2):
            if SK.index(j) > SK.index(j+1):     # 몬스터x의 인덱스가 의뢰인x의 인덱스보다 나중에 나오면 추가X
                return
        return S.append(SK)

    for i in range(SS_L-c):                     # 모든 수열 만들기.
        SS[c], SS[c+i] = SS[c+i], SS[c]
        make_S(SS, c+1)
        SS[c], SS[c + i] = SS[c + i], SS[c]

V = int(input())
for __ in range(1, V+1):
    N = int(input())
    A = dict()
    A[0] = (0, 0)                           # dict A[0] = (0, 0) 용사 위치
    for i in range(N):
        M = list(map(int, input().split()))
        for j in range(N):
            if M[j] != 0:
                A[M[j]] = (i, j)            # dict A[1] or A[-1] -> A[몬스터 1위치] , A[의뢰자 1위치]
    PM = []                                 # PM에 dict에 저장된 위치들 원하는 순서로 추가
    for i in range(len(A)//2):
        PM.append(A[i+1])           # 양수 1 몬스터 위치
        PM.append(A[-(i+1)])        # 음수 1 의뢰인 위치
    PM.append((0, 0))               # PM의 마지막 인덱스는 사용자 위치 추가
    # PM = [(몬스터 1위치), (의뢰인 1위치), (몬스터 2위치), (의뢰인 2위치),...(사용자 위치)
    NODE = [[0 for i in range(len(PM))] for j in range(len(PM))]    # [[0,1,2,1], [1,0,3,1] ...]
    # NODE[i][j] = 거리  => i, j를 node 번호라고 치면 PM의 인덱스 0은 노드0 PM의 인덱스 1은 노드 1 이다.
    # 몬스터 1위치의 인덱스는 0, 노드는0, 의뢰인 1 위치의 인덱스는 1, 노드는1 ...
    for i in range(len(PM)):
        for j in range(len(PM)):
            if i != j:
                NODE[i][j] = (abs(PM[j][0]-PM[i][0])+abs(PM[j][1]-PM[i][1])) # NODE[몬스터1위치][의뢰인2위치] = 두 곳의 거리
    SS = list(range(len(NODE)-1)) # 현재위치를 제외한 나머지들의 index를 SS에 넣는다.
    SS_L = len(SS)
    S = []                        # S에는 index의 수열을 뽑아 넣는데, 이때 몬스터1,2,3은 각각 의뢰인 1,2,3의 인덱스보다 먼저 나오는 수열만 뽑는다.
    make_S(SS, 0)                 # 수열 뽑기, 0은 같은 함수가 1번 돌때마다 1씩 증가.
    print(NODE)
    min_ = 1000                   # 충분히 큰 수 뽑기.
    for i in S:
        t = 0                     # S에서 뽑은 수열 1가지 케이스에 대해 total 움직인 거리
        x = -1                    # x=-1을 쓰는 이유는 NODE의 마지막은 처음 시작위치에서 갈수있는 곳들의 거리를 저장 -> NODE[-1]
        for j in range(SS_L):
            t += NODE[x][i[j]]    # 시작 위치에서 움직이다.
            x = i[j]              # 그리고 x값은 다음 인덱스로 움직인다.
        if min_ > t:              # 최소 이동값 뽑기.
            min_ = t
    print(f'#{__} {min_}')
