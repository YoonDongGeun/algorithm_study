N,M=list(map(int,input().split()))
Chess=[]
clist=[]
sollist=[]
for i in range(N):
    Chess.append(input().replace('B','1').replace('W','0')) #W와B를0과 1로 바꿈(본인에게 이것이 편함.)
def che(a,b):
    cnt1=0#1,3,5 순으로 B일때 총 B의 갯수
    cnt2=0#2,4,6 순으로 B일때 총 B의 갯수
    for i in range(a,a+8):
        for j in range(b,b+8):
            if (i%2==0)and(j%2==0):
                if (Chess[i][j]=='1'):#1,3,5순서에 B가 있을때 +1
                    cnt1+=1
            if (i%2==1)and(j%2==1): #2번쨰 줄은 1,3,5가 2,4,6순으로 대체
                if Chess[i][j]=='1':
                    cnt1+=1 #1,3,5 지역의 Black갯수
        
            if (i%2==0)and(j%2==1): #2,4,6 순서에 B가 있을때 +1
                if Chess[i][j]=='1':
                    cnt2+=1
            if (i%2==1)and(j%2==0): #2번째 줄은 1,3,5순서에 B있을떄 +1
                if Chess[i][j]=='1':
                    cnt2+=1  #2,4,6 지역의 Black 갯수
    return cnt1,cnt2 #cnt1과 cnt2 반환

for n in range(0,N-7):
    for m in range(0,M-7):
        clist.append(che(n,m)) #모든 8X8경우의 수에 대해 cnt1,cnt2 가져오기
for a in clist:
    if a[0]>=a[1]: #만약 cnt1,cnt2값의 경우를 따져 최소로 칠해야할 횟수 얻기.
        sollist.append(abs(a[0]-32)+a[1])
    else:
        sollist.append(abs(a[1]-32)+a[0])
print(min(sollist))#모든 경우에 대해 얻은 최소 칠해야할 수 중에 최솟값 가져오기.
