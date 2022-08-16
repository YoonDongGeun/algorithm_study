for j in ['']*4:
    x1, y1, x2, y2, xx1, yy1, xx2, yy2 = map(int, input().split())
    RECTANGLE_1 = set() # 계산 편리를 위해 집합 생성
    RECTANGLE_2 = set()
    for x in range(x1,x2+1):
        for y in range(y1,y2+1):
            RECTANGLE_1.add((x,y)) # 사각형 1이 차지하는 좌표 추가
    for x in range(xx1,xx2+1):
        for y in range(yy1,yy2+1):
            RECTANGLE_2.add((x,y)) # 사각형 2가 차지하는 좌표 추가
    REC1_AREA = len(RECTANGLE_1) # 사각형 1 넓이
    REC2_AREA = len(RECTANGLE_2) # 사각형 2 넓이
    if REC1_AREA + REC2_AREA != len(RECTANGLE_1 | RECTANGLE_2): # 만약 겹치면
        if abs(REC1_AREA + REC2_AREA - len(RECTANGLE_1 | RECTANGLE_2)) == 1:
            print('c') # 만약 겹친 수가 1이면 모서리 닿음.
        else:
            overlap = list(RECTANGLE_1 & RECTANGLE_2) # 겹친 구간 리스트 반환
            case1 = 0
            case2 = 0
            for i in overlap:
                if i[0] != overlap[0][0]: # x좌표가 모두 같지 않으면 case1 = 1
                    case1 = 1
                    break
            for i in overlap:
                if i[1] != overlap[0][1]: # y좌표가 모두 같지 않으면 case2 = 1
                    case2 = 1
                    break
            if case1 == 1 and case2 == 1: # x,y좌표가 모두 같지 않으면 그냥 겹침
                print('a')
            else: # x,y중 1개 좌표가 모두 동일하면 모서리 겹침
                print('b')
    else: # 원소 갯수가 합집합에서 안줄면 안겹치는 케이스
        print('d')