'''
def res(A,n):
    B = []
    cnt = 0
    n -= 1
    for i in A:
        if i !=0 and i!=9:
            B.append(i+1)
            B.append(i-1)
            cnt += 2
            continue
        if i==0:
            B.append(i+1)
        else:
            B.append(i-1)
        cnt += 1 
    return cnt if n==1 else res(B,n)
A = [1,2,3,4,5,6,7,8,9]
N = int(input())
print(res(A,N)) if N !=1 else print(9)
'''
'''
res(1) = 1
def res(n):
    if n==1:
        return 9
        res(n) = res(n-1) * 2 
    return 
'''
A = [-1,0,1,2,3,4,5,6,7,8,9,10]
A_DICT = dict()
for i in A:
    A_DICT[i] = 1

A_DICT[0] = 0
A_DICT[-1] = 0
A_DICT[10] = 0
cnt = 1
C = int(input())
if C != 1:
    while cnt < C:
        B_DICT = dict(A_DICT.items())
        cnt += 1
        for i in range(10):
            A_DICT[i] = B_DICT[i - 1] + B_DICT[i+1]
    print(sum(A_DICT.values())%1000000000)
else:
    print(9)


#9 17 32 61 116 222 424 813 1556 2986
#18-1  34-2  64-3  122-6   232-10 444-20  848-35  1626-70 3112-126