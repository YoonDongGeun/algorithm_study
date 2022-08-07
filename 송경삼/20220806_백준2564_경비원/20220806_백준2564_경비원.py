X,Y=map(int, input().split())
N=int(input())
L=[list(map(int,input().split())) for _ in range(N+1)]  #input을 받습니다.

for n,i in enumerate(L):    #받은 input을 순회하면서 다음과 같이 갱신해줍니다.
    if i[0]==1:     #inut이 윗변이라면
        L[n][0]=1   #부호는 +, 거리는 그대로
    elif i[0]==2:   #input이 아랫변이라면
        L[n][0]=-1  #부호는 -, 거리에 Y축을 더해줌
        L[n][1]+=Y
    elif i[0]==3:   #input이 왼변이라면
        L[n][0]=-1  #부호는 -
    else:
        L[n][0]=1   #input이 오른변이라면
        L[n][1]+=X  #부호는 + 거리는 X를 더해줌 

sum=0
for a in L[:-1]:    #갱신한 L을 마지막항 빼고 순회하면서
    sum+=min(abs(a[1]*a[0]-L[-1][0]*L[-1][1]),2*(X+Y)-abs(a[1]*a[0]-L[-1][0]*L[-1][1]))
print(sum)  
#값*부호를 마지막항의 값*부호에서 뺀 값,
#위 값을 둘레에서 뺀 값 중 작은 값을 sum에 더해줍니다.



