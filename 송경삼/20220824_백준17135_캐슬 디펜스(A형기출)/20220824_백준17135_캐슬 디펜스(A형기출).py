def find_Enmy(I,J): #궁수의 위치를 받아 가장 가까운 적을 찾아 조준하는 함수입니다.
    for d in range(D):
        for dx in range(-d,d+1):    
            c_i=-(d+1)+abs(dx)+I    #탐색할 i좌표
            c_j=J+dx                #탐색할 j좌표
            if 0<=c_j<M and -N<=c_i<0 and Enmy_list[c_i][c_j]==1 and (c_i,c_j) not in kill:
                return c_i,c_j  #있으면 좌표
    return 0    #없으면 0 

N,M,D=map(int,input().split())
Enmy_list=[list(map(int,input().split())) for _ in '_'*N]
R=[i for i in range(M)] #조합을 만들 보조리스트입니다.
ARC_list=[[]]   #궁수 위치 조합입니다.
for _ in '___': #궁수의 위치를 세군데 뽑을예정입니다.
    sub=[]
    for ARC in ARC_list:
        for r in R:
            if ARC==[] or r > ARC[-1]:sub.append(ARC+[r])
    ARC_list=sub[:]
    #궁수 배치 가능 조합 완성

max=0   #최대값을저장할변수
for ARC in ARC_list:    #궁수조합을 차례대로 순회하면서
    kill=[] #죽인 병사를 저장할 리스트
    total=0 #이번 조합에서 죽인 병사수
    for i in range(N):  #병사가 움직이는대신 성이 움직이는 거로 합니다.
        target={0}  #해당 공격턴 조준리스트입니다.(중복 조준 되므로 set 활용)
        for arc in ARC: #궁수 조합의 각 궁수들을 돌면서
            target.add(find_Enmy(-i,arc))   #각자의 조준점을 받아옵니다.
        target.discard(0)   # 0을 빼고
        for ii,jj in target:kill.append((ii,jj))    #죽인리스트에 추가
        total+=len(target)  #죽인 병사의 수를 더합니다.
    if total>max:max=total  #이번조합에서 총죽인병사가 최대값보다 크다면 갱신합니다.
print(max)
