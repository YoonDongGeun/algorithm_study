I=input;N=int(I());A=[]
L=list(map(int,I().split()))
for i in range(N):
    A.insert(L[i] ,i+1)
print(*A[::-1])