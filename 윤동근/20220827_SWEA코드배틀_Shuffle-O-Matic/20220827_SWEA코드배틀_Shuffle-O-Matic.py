def shuffle(x, nc):             # 섞기 x값에 따라 다르게 섞임. nc는 카드뭉치
    temp = nc[:]                # 셔플 후의 카드뭉치 temp
    for i in range(N):
        temp[i] = nc[idxL[x][i]]
    return temp

def i_shuffle(c, i):            # 셔플 5번까지만 반복.
    global cnt                  # 최소 cnt값 찾기.
    if i >= cnt:                # i가 찾은 cnt와 같거나 크면 멈추기
        return
    if (c == idxL[0]) or (c[::-1] == idxL[0]):  # 오름차순, 내림차순 모두 검색. idxL[0]은 인덱스 0123456 같이 순서대로.
        if cnt > i:
             cnt = i
        return
    if i == 5:                  # i가 5넘어가면 안돼서 return.
        return
    for j in range(1, N):       # 앞에 숫자가 1인 이유는 0이면 어처피 그대로이기 때문. idxL[0] = 1,2,3,4,5,6 shuffle(x,ne)는 idxL[x]안의 요소들 사용.
        nc = shuffle(j, c)      # 섞기
        i_shuffle(nc, i+1)      # 1번에 i에 1씩 더함

T = int(input())
for _ in range(1, T+1):
    N = int(input())                                    # 카드 개수 받기
    cards = list(map(int, input().split()))             # 카드 순서 받기
    idx = list(range(N))                                # 인덱스
    half = N//2                                         # 카드 뭉치 절반 위치
    for i in range(N):
        cards[i] -= 1                                   # 카드번호를 편하게 index로 만들기
    B = []                                              # 카드 x=?일때 셔플할때 바뀌는 순서 저장하는 리스트
    for i in range(N//2):
        A= []
        for k in range(half-1-i, half+1+i, 2):
            A.append((k, k+1))
        B.append(A)                                     # half까지 할때 바꿔야 하는 인덱스들 저장
    for i in range(half-2, -1, -1):                     # x가 half 이후에는 그 역순이므로 역순들 저장.
        B.append(B[i])                                  # B = [ [(1,2)], [(0,1), (2,3)], [(1,2)] ] 와 같은 순서 x=0일때 1,2인덱스만 바꾸고 x=1일때 1,2에 이어서 0,1과 2,3인덱스 바꿔야한다.
    idxL = [idx[:]]                                     # x=0일때부터 N-1떄까지 0123456의 카드를 셔플로 바꿨을때 그 위치들을 모두 저장.
    for i in B:
        for x, y in i:
            idx[x], idx[y] = idx[y], idx[x]
        idxL.append(idx[:])                             # idxL = [[0, 1, 2, 3, 4, 5], [0, 1, 3, 2, 4, 5], [0, 3, 1, 4, 2, 5], [3, 0, 4, 1, 5, 2], [3, 4, 0, 5, 1, 2], [3, 4, 5, 0, 1, 2]]
    cnt = 6                                             # cnt는 5를 넘지 못한다. 따라서 최대값 6설정
    i_shuffle(cards, 0)                                 # 카드 최대 5번까지 섞으며 같은값 나온것 저장.
    print(f'#{_} {cnt if cnt !=6 else -1}')             # cnt값 변경된 것 출력. 단 6일경우 -1 출력


