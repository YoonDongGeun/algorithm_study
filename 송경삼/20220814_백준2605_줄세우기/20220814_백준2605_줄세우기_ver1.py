N=int(input());A=[]
L=list(map(int,input().split()))
for i in range(N):
    A.insert(L[i] ,i+1)
print(*reversed(A))