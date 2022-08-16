for _ in ['']*4:
    x1, y1, x2, y2, xx1, yy1, xx2, yy2 = map(int, input().split())
    
    x_list = [0]*50001 # x축 차지하는 리스트 생성
    y_list = [0]*50001 # y축 차지하는 리스트 생성
    for i in range(x1,x2+1): # x,y축 리스트 사각형 차지하는 공간 1씩 더함
        x_list[i] += 1
    for i in range(xx1,xx2+1):
        x_list[i] += 1
    for i in range(y1, y2+1):
        y_list[i] += 1
    for i in range(yy1, yy2+1):
        y_list[i] += 1
    x_cnt = x_list.count(2) # 2인 공간은 겹치는 공간 갯수 세기.
    y_cnt = y_list.count(2)
    if x_cnt > 1 and y_cnt > 1: # x, y에서 겹치는 공간 2개 넘으면 일반 겹침
        print('a')
    elif x_cnt == 1 and y_cnt == 1: # x, y에서 겹치는 공간 1개면 꼭지점
        print('c')
    elif (x_cnt == 1 and y_cnt > 1) or (x_cnt > 1 and y_cnt == 1):
        print('b') # 1개는 1이고 다른 1개는 2 이상이면 모서리
    else:
        print('d') # 2 자체가 없으면 안겹침