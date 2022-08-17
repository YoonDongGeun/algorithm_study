height_list = [int(input()) for i in range(9)]
sub_height = sum(height_list) - 100 # 7개의 합이 100이긴 보다 2개의 합이 나머지의 합인 경우 더 빠름.
case = 0    # 2중 for문 탈출용
for i in range(len(height_list)-1):
    for j in range(i+1, len(height_list)):
        if sub_height == height_list[i] + height_list[j]:   # 전체에서 100 뺀 나머지와 합이 같은 수 2개
            del height_list[j]  # 두 수 삭제
            del height_list[i]
            case = 1    # case=1이면 2중 for문 탈출
            break
    if case == 1:
        break
height_list.sort()  # 오름차순 정렬
for i in height_list:
    print(i)