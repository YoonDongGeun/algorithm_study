for j in ['']*4:
    x1, y1, x2, y2, xx1, yy1, xx2, yy2 = map(int, input().split())
    RECTANGLE_1 = set()
    RECTANGLE_2 = set()
    for x in range(x1,x2+1):
        for y in range(y1,y2+1):
            RECTANGLE_1.add((x,y))
    for x in range(xx1,xx2+1):
        for y in range(yy1,yy2+1):
            RECTANGLE_2.add((x,y))
    REC1_AREA = len(RECTANGLE_1)
    REC2_AREA = len(RECTANGLE_2)
    if REC1_AREA + REC2_AREA != len(RECTANGLE_1 | RECTANGLE_2):
        if abs(REC1_AREA + REC2_AREA - len(RECTANGLE_1 | RECTANGLE_2)) == 1:
            print('c')
        else:
            overlap = list(RECTANGLE_1 & RECTANGLE_2)
            case1 = 0
            case2 = 0
            for i in overlap:
                if i[0] != overlap[0][0]:
                    case1 = 1
                    break
            for i in overlap:
                if i[1] != overlap[0][1]:
                    case2 = 1
                    break
            if case1 == 1 and case2 == 1:
                print('a')
            else:
                print('b')
    else:
        print('d')