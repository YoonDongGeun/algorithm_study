def S(n):
    return sub-L[n-1]+L[n+M-1]   #이전항 제거 다음항 추가 함수
I=lambda :map(int,input().split())
N,M=I()
L=list(I())
m=sub=sum([L[i] for i in range(M)])  #초항 값 저장
for i in range(1,N-M+1):
    sub=S(i)
    if sub>m:m=sub  #max값 갱신
print(m)