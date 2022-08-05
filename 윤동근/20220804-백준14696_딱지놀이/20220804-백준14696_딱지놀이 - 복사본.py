def who(A,B):
    cnt=0
    for i in range(1,5)[::-1]:
        a,b=A.count(i),B.count(i)
        if a==b:
            pass
        elif a>b:
            return 'A'
        else:
            return 'B'
        cnt+=1
        if cnt==4:
            return 'D'
C=[]       
for i in range(int(input())):
    A=list(map(int,input().split()))
    B=list(map(int,input().split()))
    C.append(who(A[1:],B[1:]))
for i in range(len(C)):print(C[i])