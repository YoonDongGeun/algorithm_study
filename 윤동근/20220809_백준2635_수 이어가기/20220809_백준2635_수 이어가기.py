def a(F):
    max=0
    if F==1:
        return 4, [1, 1, 0, 1]

    for i in range(F//2,F):
        NL=[F]
        NL.append(i)
        while NL[-1]>=0:
            NL.append(NL[-2]-NL[-1])
        cnt=len(NL)-1

        if max<cnt:
            max=cnt
            maxlist=NL[:-1]

    return max, maxlist

N=int(input())
c,d=a(N)
print(c)
print(*d)