for _ in ['']*4:
    x1, y1, x2, y2, xx1, yy1, xx2, yy2 = map(int, input().split())
    
    x_max = max(x1, x2, xx1, xx2)
    x_min = min(x1, x2, xx1, xx2)
    y_max = max(y1, y2 ,yy1, yy2)
    y_min = min(y1, y2, yy1, yy2)
    #1, 3  2,4   1234
    x_len = x_max - x_min
    y_len = y_max - y_min
    x1_len = x2 - x1
    xx1_len = xx2 - xx1
    y1_len = y2 - y1
    yy1_len = yy2 - yy1

    if x_len > x1_len + xx1_len:
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
