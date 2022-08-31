A=input()
L=[-1]*26
for i in range(len(A)):
    sub=ord(A[i])-97
    if L[sub]==-1:L[sub]=i   
print(*L)
