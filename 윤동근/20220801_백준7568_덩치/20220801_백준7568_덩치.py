N=int(input())
B=[]
C=[]
for i in range(N):
    a=list(map(int,(input().split())))
    B.append(a)

for i in range(N):
    cnt=1
    for j in range(N):
        if (B[i][0]<B[j][0]) and (B[i][1]<B[j][1]):
            cnt+=1
    C.append(cnt)

print(*C)