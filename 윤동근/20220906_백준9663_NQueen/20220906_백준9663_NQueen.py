def search():
    global cnt
    ny = len(STACK)
    if ny == N:
        cnt += 1
        STACK.pop()
        return
    else:
        array = set(range(N))
        for j in range(ny):
            if 0 <= STACK[j]+ny-j < N:
                array -= {STACK[j]+ny-j}
            if 0 <= STACK[j]-ny+j < N:
                array -= {STACK[j]-ny+j}
            array -= {STACK[j]}
        for nx in array:
            used_x[nx] = 1
            STACK.append(nx)
            search()
            used_x[nx] = 0
    STACK.pop()
for _ in range(1, int(input())):
    N = int(input())
    used_x = [0]*N
    cnt = 0
    STACK = []
    for i in range(N):
        STACK.append(i)
        used_x[i] = 1
        search()
        used_x[i] = 0
    print(f'#{_} {cnt}')