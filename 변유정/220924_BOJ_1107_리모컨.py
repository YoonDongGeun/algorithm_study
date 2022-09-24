# 브루트포스
# 문제점 고쳐가기
# 1. bfs식으로 돌려가면서 했는데 그럴필요없었다
# 1-1. 글자수 길이  / 글자수 길이 + 기호쓰기 / 기호쓰기 중 작은 값 되돌려주기
# 2. Nameerror 발생
# 2-1. 이거는 고장난 버튼이 있는지만 고려했는데, 아닌 것도 고려해주어야한다
# 

goals = int(input())
broke = int(input())
ans = abs(100 - goals)
if broke != 0:
    lst = list(input().split())
else:
    lst = list()

for now in range(1000001):
    for num in str(now):
        if num in lst:
            break
    else:
        ans = min(ans, len(str(now)) + abs(now - goals))
print(ans)