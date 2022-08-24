def archer_p(M):                            # 궁수 3명 배치표(모든 경우)
    for i in range(M-2):
        for j in range(i+1, M-1):
            for k in range(j+1, M):
                archer.append((i, j, k))

def make_Distance_range(D):                  # 사거리 따른 범위 만들기
    start = 1
    for _ in range(0, D-1):
        start += 2*_ - 1                    # 범위는 1,3,5,7 칸씩 쏠 수 있는 칸 증가.
        L = len(Ds)
        Ds.append((Ds[start][0], Ds[start][1] - 1)) # 처음엔 왼쪽 1칸 생성
        for i in range(start, L):
            Ds.append((Ds[i][0]-1, Ds[i][1]))   #가장 바깥쪽 범위에서 위로 1칸씩 생성
        Ds.append((Ds[L-1][0], Ds[L-1][1]+1))   # 마지막은 오른쪽 한칸 생성
        # 위 순서대로 list에 append 해야 왼쪽부터 탐색가능

N, M, D = map(int, input().split())                             # 행, 열, 범위
castle = [list(map(int, input().split())) for i in range(N)]    # 성 앞 적들
archer = []
archer_p(M)                                                     # 궁수 가능한 모든 배치
Ds = [(-1, 0)]          # 궁수 위치에서 위에 1칸 공격 가능(1칸일때)
make_Distance_range(D)  # 사거리 따른 사거리 표 작성
max_ = 0
for i in archer:    # 공수 모든 배치에 대해서 탐색.
    new_castle = [castle[j][:] for j in range(N)]   # 매 궁수 배치마다 적들 초기화.
    cnt = 0
    for j in range(N):  # 행의 갯수만큼 시행. (끝나면 1칸씩 위로 이동하기 위함)
        target = set()  # 잡는 적이 몇개인지 추가. (set은 중복되면 1개만 추가됌)
        for l in range(3):  # 궁수 3명 모두 적 찾기
            for k in Ds:    # 사정 거리 내 탐색
                y = N + k[0] - j        # -j 는 1번 시행마다 1씩 더해져 적이 아래로 내려오는 효과.
                x = i[l]+k[1]
                if -1 < x < M and y > -1:   # x,y 범위가 적들 범위 넘지 않게.
                    if new_castle[y][x] == 1:   # 적 있으면 리스트에 추가하고 break.
                        target.add((y, x))
                        break
        for l in target:                # 잡은 적들 0으로 만들기
            new_castle[l[0]][l[1]] = 0

        cnt += len(target)              # 죽인 적만큼 cnt에 추가
    if max_ < cnt:                      # 가장 큰것만 갖기.
        max_ = cnt
print(max_)