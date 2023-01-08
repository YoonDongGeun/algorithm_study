### 숏코딩

num_dic = {"zero":"0", "one":"1", "two":"2", "three":"3", "four":"4", "five":"5", "six":"6", "seven":"7", "eight":"8", "nine":"9"}

def solution(s):
answer = s
for key, value in num_dic.items():
answer = answer.replace(key, value)
return int(answer)

### 느낀점

오랜만에 파이썬을 쓰니까 문법도 다 까먹고 내장함수도 파이썬거였는지 자바스크립트꺼였는지 헷갈린다. 부지런히 풀어서 기억을 회복시켜야겠다.

#### 오늘 안 것

repalce는 자바스크립트, 파이썬 둘다 있다. 일단 검색해보자!
