for _ in range(4):
    L = list(map(int, input().split()))
    x1, y1, x2, y2 = L[0], L[1], L[2], L[3]
    p1, q1, p2, q2 = L[4], L[5], L[6], L[7]
    if (x2 < p1) or (p2 < x1) or (q1 > y2) or (y1 > q2):
        print('d')
    elif (x2 == p1 and y2 == q1) or (x2 == p1 and y1 == q2) or (x1 == p2 and y1 == q2) or (x1 == p2 and y2 == q1):
        print('c')
    elif p1 == x2 or x1 == p2 or y1 == q2 or y2 == q1:
        print('b')
    else:print('a')