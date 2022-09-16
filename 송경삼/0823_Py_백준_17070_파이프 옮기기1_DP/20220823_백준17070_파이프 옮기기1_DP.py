N=int(input())
Room=[[1]*(N+2)]+[[1]+list(map(int,input().split()))+[1] for _ in '_'*N]+[[1]*(N+2)]
    #index를 쉽게 다루기 위해 1로 둘러싼 배열을 만듭니다.
sub=[[[0,0,0]]*(N+2) for _ in '_'*(N+2)]    #각 좌표의 값을 갱신할 공간을 만듭니다.
                                            #[왼쪽에서 오는경우의수,대각선에서 오는경우의수,위쪽에서 오는 경우의수] 입니다.
sub[1][2]=[1,0,0] #초기값을 정해줍니다.
for i in range(1,N+1):  #이동 특성상 j의 0,1,2 index는 절대 이동못하므로 순회하지않습니다.
    for j in range(3,N+1):
        if Room[i][j]==1:   #만약 해당 좌표가 이동불가능한 공간이라면 건너뜁니다.
            continue
        fr1=sub[i][j-1]     #왼쪽의 dp
        fr2=sub[i-1][j-1]   #대각선의 dp
        fr3=sub[i-1][j]     #위쪽의 dp
                #이동 가능한지 여부를 따지면서 dp를 갱신합니다.
        SUB1=fr1[1]+fr1[0] if Room[i][j-1]!=1 else 0    #첫번째값은 왼쪽칸에 왼쪽으로 도착한경우, 대각선으로 도착한 경우의 합입니다.
        SUB2=fr2[0]+fr2[1]+fr2[2] if Room[i-1][j-1]!=1 and Room[i-1][j]!=1 and Room[i][j-1]!=1 else 0   #대각선에서 오는건 다 더해줍니다.
        SUB3=fr3[1]+fr3[2] if Room[i-1][j]!=1 else 0    #마지막값은 위쪽칸에 위쪽으로 도착한경우,대각선으로 도착한 경우의 합입니다.
        sub[i][j]=[SUB1,SUB2,SUB3] #dp표를 갱신해줍니다
print(sum(sub[N][N]))   #모든 경우의 수를 합해줍니다.