A=[]
B=[]
cnt=0
for i in range(4):
    A+=list(map(int,input().split()))
maxx=max(A[::2])
maxy=max(A[1::2])
for i in range(maxy):
    B+=[[0]*maxx]
for i in range(int(len(A)/4)):
    for k in range(A[4*i+1],A[4*i+3]):
        for j in range(A[4*i],A[4*i+2]):
            B[k][j]=1
for i in B:
    cnt+=sum(i)
print(cnt)