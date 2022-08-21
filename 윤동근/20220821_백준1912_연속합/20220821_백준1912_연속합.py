N = int(input())
nums = list(map(int, input().split()))
sum_ = 0
max_ = -1001
for i in range(N):
    if sum_ < 0:
        sum_ = 0
    sum_ += nums[i]

    if max_ < sum_:
        max_ = sum_
print(max_)