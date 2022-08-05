def who(A,B):
    if A.count('4')>B.count('4'):
        return 'A'
    if A.count('4')<B.count('4'):
        return 'B'
    if A.count('3')>B.count('3'):
        return 'A'
    if A.count('3')<B.count('3'):
        return 'B'
    if A.count('2')>B.count('2'):
        return 'A'
    if A.count('2')<B.count('2'):
        return 'B'
    if A.count('1')>B.count('1'):
        return 'A'
    if A.count('1')<B.count('1'):
        return 'B'
    return 'D'
    
C=[]       
for i in range(int(input())):
    A=input().split()
    B=input().split()
    C.append(who(A[1:],B[1:]))
for i in range(len(C)):print(C[i])