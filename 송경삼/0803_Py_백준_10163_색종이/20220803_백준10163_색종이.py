import sys
N=int(input())
cp=[]   #color paper input 정보를 저장할 공간입니다.
max_x=0 #색종이를 놓을 x축의 최대값을 저장할 공간입니다.
max_y=0 #색종이를 놓을 y축의 최대값을 저장할 공간입니다.
for _ in range(N):
    x,y,xl,yl=map(int, sys.stdin.readline().split()) #input을 받습니다.
    cp.append([x,y,xl,yl])  #cp에 저장합니다.
    if x+xl>max_x:max_x=x+xl    #최대 x값을 갱신합니다.
    if y+yl>max_y:max_y=y+yl    #최대 y값을 갱신합니다.

cnt=[0]*N   #x번째 색종이의 영역을 카운트할 공간입니다.
arr=[[0 for x_ in range(max_x)] for y_ in range(max_y)]
    #최대 x,y값으로 색종이를 놓을 적당한 공간을 만듭니다.
sub=0  #몇번째 색종이인지 카운트할 임시 변수입니다.
for paper in cp: #cp에 담긴 색종이를 순회합니다.
    sub+=1  #색종이 번호가 증가함을 뜻합니다.
    for X in range(paper[0],paper[0]+paper[2]): #해당 색종이의 X축 좌표부터 길이만큼 순회합니다.
        for Y in range(paper[1],paper[1]+paper[3]): #해당 색종이의 Y축 좌표부터 길이만큼 순회합니다.
            if arr[Y][X]!=0: #이미 색종이가 놓여있는 공간이라면
                cnt[arr[Y][X]-1]-=1 #놓여있던 색종이번호의 카운트를 뺍니다
            arr[Y][X]=sub   #그런 다음 순회하고있는 색종이를 놓습니다.
            cnt[arr[Y][X]-1]+=1 #순회하고있는 색종이 번호를 카운트합니다.
for i in cnt: #카운트 한 값을 1번째부터 N번째까지 인쇄합니다.
    print(i)

    

