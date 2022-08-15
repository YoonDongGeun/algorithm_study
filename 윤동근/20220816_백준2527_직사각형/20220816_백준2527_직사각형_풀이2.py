for _ in ['']*4:
    x1, y1, x2, y2, xx1, yy1, xx2, yy2 = map(int, input().split())
    
    x_list = [0]*50001
    y_list = [0]*50001
    for i in range(x1,x2+1):
        x_list[i] += 1
    for i in range(xx1,xx2+1):
        x_list[i] += 1
    for i in range(y1, y2+1):
        y_list[i] += 1
    for i in range(yy1, yy2+1):
        y_list[i] += 1
    x_cnt = x_list.count(2)
    y_cnt = y_list.count(2)
    if x_cnt > 1 and y_cnt > 1:
        print('a')
    elif x_cnt == 1 and y_cnt == 1:
        print('c')
    elif (x_cnt == 1 and y_cnt > 1) or (x_cnt > 1 and y_cnt == 1):
        print('b')
    else:
        print('d')