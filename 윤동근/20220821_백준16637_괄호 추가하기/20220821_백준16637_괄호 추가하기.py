def find(ex):
    N = len(ex) // 2
    B=[]
    for i in range(1 << N):
        A = []
        cnt = 0
        for j in range(N):
            if i & (1<<j):
                cnt +=1
                A.append(1)
                if cnt == 2:
                    break
            else:
                cnt = 0
                A.append(0)
        else:
            B.append(A)
    NEW_LIST = []
    for j in B:
        ex2 = list(ex)
        for i in range(len(ex2)-2,0,-2):
            if j[i//2] == 1:
                if ex2[i] == '+':
                    ex2[i-1:i+2] = [int(ex2[i-1]) + int(ex2[i+1])]
                elif ex2[i] == '-':
                    ex2[i-1:i+2] = [int(ex2[i-1]) - int(ex2[i+1])]
                else:
                    ex2[i-1:i+2] = [int(ex2[i-1]) * int(ex2[i+1])]
        NEW_LIST.append(ex2)
    for j in NEW_LIST:
        while len(j) != 1:      # 계산
            if j[1] == '+':
                j[0:3] = [int(j[0]) + int(j[2])]
            elif j[i] == '-':
                j[0:3] = [int(j[0]) - int(j[2])]
            else:
                j[0:3] = [int(j[0]) * int(j[2])]
    max_= NEW_LIST[0][0]
    for i in NEW_LIST:
        if max_ < i[0]:
            max_ = i[0]
    print(max_)


N = int(input())
find(input())