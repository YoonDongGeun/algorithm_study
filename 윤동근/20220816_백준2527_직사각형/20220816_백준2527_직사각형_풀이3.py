for _ in ['']*4: # 4번 수행(케이스가 4개)
    x1, y1, x2, y2, xx1, yy1, xx2, yy2 = map(int, input().split())
    
    x_max = max(x1, x2, xx1, xx2) # x좌표 최대값
    x_min = min(x1, x2, xx1, xx2) # x좌표 최소값
    y_max = max(y1, y2 ,yy1, yy2) # y좌표 최대값
    y_min = min(y1, y2, yy1, yy2) # y좌표 최소값

    x_len = x_max - x_min # x 최대 길이
    y_len = y_max - y_min # y 최대 길이
    x1_len = x2 - x1 # 사각형 1 x길이
    xx1_len = xx2 - xx1 # 사각형 2 x길이
    y1_len = y2 - y1 # 사각형 1 y길이
    yy1_len = yy2 - yy1 # 사각형 2 y길이

    if x_len > x1_len + xx1_len: # 사각형1,2의 길이합과 최대 좌표 사이 길이에 따른 분류
            print('d')
    elif x_len == x1_len + xx1_len:
        if y_len > y1_len + yy1_len:
            print('d')
        elif y_len == y1_len + yy1_len:
            print('c')
        else:
            print('b')
    else:
        if y_len > y1_len + yy1_len:
            print('d')
        elif y_len == y1_len + yy1_len:
            print('b')
        else:
            print('a')
