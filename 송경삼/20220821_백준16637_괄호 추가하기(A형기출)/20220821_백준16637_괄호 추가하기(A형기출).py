def cal(case):  #괄호를 추가할 case를 받아 식을 계산하고 return해주는 함수
    copy_q=q[::]    #pop을 사용하기 위해 list를 복사하고 거꾸로 순회합니다.
    for i in case[::-1]:    #우선 괄호를 먼저 계산합니다
        B=copy_q.pop(i)     #B는 연산자
        C=copy_q.pop(i)     #C는 뒷수입니다.
        if B=='*':
            copy_q[i-1]*=C  #연산자가 곱하기면 앞수에 뒷수를 곱한값을 저장
        elif B=='+':
            copy_q[i-1]+=C  #덧셈
        elif B=='-':
            copy_q[i-1]-=C  #뺄셈
    for _ in '_'*(num_oper-len(case)):  #남은연산 횟수를 수행합니다
        B=copy_q.pop(1) 
        C=copy_q.pop(1)
        if B=='*':
            copy_q[0]*=C
        elif B=='+':
            copy_q[0]+=C
        elif B=='-':
            copy_q[0]-=C
    return copy_q[0]    #계산한 값을 리턴합니다

N=int(input())
q=list(input())
for j in range(N):
    if j%2==0:q[j]=int(q[j])    #계산을위해 q의 숫자는 int로 바꿔줍니다
oper_index=[i for i in range(N) if i%2] #조합을 구하기 위한 연산자 index 리스트입니다
num_oper=N//2   #연산자의 총 개수입니다
oper_combi=[[[]]]   #조합을 저장하기 위한 저장공간입니다
max_choice=-(-num_oper//2)  #최대로 고를 수 있는 연산자의 개수입니다

ans=-2**31  #답을 내기 위한 기본값을 지정해줍니다

for _ in '_'*max_choice:    # comb를 구하기 위해 반복합니다
    sub=[]  #임시 저장 공간
    for combi in oper_combi[-1]:    #바로 전에 골랐던 조합을 꺼내서
        for i in oper_index:    # 연산자 인덱스를 순회합니다
            if combi==[]:sub.append(combi+[i])  #바로 전이 0개를 골랐던 상황이라면 그냥 조합을 추가해주고
            elif i>combi[-1]+2:sub.append(combi+[i])    #1개이상이라면 마지막항보다 큰 값중에 바로 옆 값이 아닌 조합을 추가해줍니다
    oper_combi.append(sub) # n개를 뽑은 리스트를 combi list에 추가해줍니다

for x in oper_combi: #만든 combi 리스트를 활용합니다
    for case in x:  #n개를 뽑은 연산자 case를
        result=cal(case)    #계산해서 값을 저장합니다
        if result>ans:ans=result    #계산 값으로 최대값을 갱신해줍니다

print(ans)