r=range(5)
def check(N):   #값을 읽어 좌표를 반환해주는 함수입니다.
    for x in r:
        for y in r:
            if L[x][y]==N:return x,y

def bingo(x,y,dx,dy):   #현재 좌표와 방향을 받아 빙고체크를하는 함수입니다.
    for c in r:
        if L[x-c*dx][y-c*dy]!=0:
            return 0
    return 1 

L=[list(map(int,input().split())) for _ in r]#빙고판
A=[]
for _ in r:
    A+=list(map(int,input().split()))#부를번호

cnt=0 #빙고횟수 체크용

for n in range(25): #25개의 번호를 순서대로 부릅니다.
    x,y=check(A[n]) #부를 번호의 좌표를 체크합니다.
    L[x][y]=0   #해당 좌표를 0으로 바꾸면서 체크합니다.
    if bingo(x,y,1,0)==1:cnt+=1 #해당 좌표의 x축 빙고를 체크합니다.
    if bingo(x,y,0,1)==1:cnt+=1 #해당 좌표의 y축 빙고를 체크합니다.
    if x==y and bingo(x,y,1,1)==1:cnt+=1    #x와 y가 같다면 대각선까지 체크합니다.
    if x+y==4 and bingo(4,0,1,-1)==1:cnt+=1 #x와 y가 합이 4라면 다른 대각선까지 체크합니다.
    if cnt>=3:break #cnt가 3이상이 되면 종료합니다.
print(n+1)  #부른 번호 개수를 반환합니다.
