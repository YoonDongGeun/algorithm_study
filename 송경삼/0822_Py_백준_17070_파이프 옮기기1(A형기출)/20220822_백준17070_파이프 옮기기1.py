N=int(input())
Room=[[1]*(N+2)]+[[1]+list(map(int,input().split()))+[1] for _ in '_'*N]+[[1]*(N+2)]
        #DFS와 빽트래킹을 쓰기 위해 행렬을 1로 감싸서 인풋을 받습니다.
stack=[(1,2,0)] #처음의 i행,j행,파이프의 방향입니다. 0:수평 1:대각 2:수직
cnt=0       #경로의 수 입니다.
while stack!=[]:        #스택이 빌때까지 반복합니다
    I,J,d=stack.pop()   #top을 하나 뽑습니다.
    sub=[]      #해당 좌표와 방향에서 쓰일 임시 리스트입니다.
    I2=I+1      #연산량을 줄이기 위해 다음 I,J좌표를 저장
    J2=J+1      
    sub.append(Room[I][J2])     #오른쪽을 확인
    sub.append(Room[I2][J2])    #대각선을 확인
    sub.append(Room[I2][J])     #아래쪽을 확인
    if sub==[0,0,0]:            #셋다 비어있다면 대각선을 봅니다.
        if J2==N and I2==N:cnt+=1   #도착했다면 카운트만하고
        else:stack.append((I2,J2,1))    #도착이 아니라면 대각선을 스택에 추가
    if d!=2 and sub[0]==0:          #오른쪽으로 갈 수 있으면 오른쪽도 확인
        if I==N and J2==N:cnt+=1
        else:stack.append((I,J2,0))
    if d!=0 and sub[2]==0:          #왼쪽도 갈 수 있으면 왼쪽도 확인
        if I2==N and J==N:cnt+=1
        else:stack.append((I2,J,2))
print(cnt)  #인쇄를 합니다.
