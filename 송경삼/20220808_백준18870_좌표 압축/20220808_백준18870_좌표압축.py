import sys
N=int(input()) 
L=list(map(int, sys.stdin.readline().split()))  #input을 받습니다.
sub=sorted(enumerate(L), key=lambda x:x[1])
        #L을 enumerate 한 배열을 값을 기준으로 정렬합니다.
ans=[0]*N   #정답을 저장할 리스트입니다.
cnt=0   #값을 지정할 변수 입니다.
for v in range(1,N):    #1부터 차례대로
    if sub[v][1]>sub[v-1][1]:   #이전항보다 현재항이 크다면
        cnt+=1  #cnt를 1증가해줍니다.
    ans[sub[v][0]]=cnt  #숫자의 위치를 찾아서 cnt 숫자로 갱신해줍니다.
A=' '.join(map(str, ans))   #숫자 리스트를 문자열로 바꿉니다.
print(A)
