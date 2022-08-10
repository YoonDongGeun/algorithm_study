def a(F): #숫자 N에 대하여 그다음 임의의 수 X1(X는 0이상 N이하)에 대하여 N-X1=X2이고 그다음 X1-X2=X3로 계속 수가 이어진다.
          #그러나 X의 값이 음수가 되면 멈추게 된다. 그래서 숫자 N에 대해서 가장 많이 이어지는 값 max와 그 떄의 음수가 아닌 리스트 maxlist를 반환하는 함수.
    max=0
    if F==1: #들어온 수가 1이면 4를 반환한다. 이때는 예외적이라서 1가지 경우만 넣었다.
        return 4, [1, 1, 0, 1]

    for i in range(F//2,F): #F의 절반보다 작은 수를 다음수에 넣으면 바로 음수가 나오게 된다. 따라서 최대한 범위를 줄여준다.(간단하게 수학적 계산)
        NL=[F]
        NL.append(i) #N의 다음수로 i를 넣어주는데 i는 N의 절반 부터 시작한다.
        while NL[-1]>=0:
            NL.append(NL[-2]-NL[-1]) #N과 i를 시작으로 계속 이어나가고, NL리스트의 마지막이 음수가 되면 끝나게 된다.
        cnt=len(NL)-1 #마지막 음수는 제거한 갯수이기 때문에 1을 뺀다.

        if max<cnt:
            max=cnt
            maxlist=NL[:-1] #가장 많이 이은 x값과 그 리스트를 넣어준다.

    return max, maxlist

N=int(input())
c,d=a(N)
print(c)
print(*d)