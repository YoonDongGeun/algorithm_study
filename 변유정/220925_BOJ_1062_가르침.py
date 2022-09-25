## 여러 방식으로 풀었지만 계속 시간초과나서 잠시 미루기

def choose(now,cnt):
    global ans

    if cnt + 5 == K:
        snt = 0
        for word in words:
            flag = 0
            for apb in word:
                if used[ord(apb) - alpha] == 0:
                    flag = 1
                    break
            if flag == 0:
                snt += 1
        if ans < snt:
            ans = snt
        return

    for i in range(now,26):
        if used[i] == 1:
            continue
        used[i] = 1
        choose(i+1,cnt+1)
        used[i] = 0

N, K = map(int,input().split())
used = [0]*26
alpha = ord('a')
used[ord('a') - alpha] = 1
used[ord('n') - alpha] = 1
used[ord('c') - alpha] = 1
used[ord('i') - alpha] = 1
used[ord('t') - alpha] = 1
words = []
ans = 0
for _ in range(N):
    langs = input()
    langs = langs[4:-4]
    words.append(langs)

if K < 5:
    print(0)
elif K == 26:
    print(N)
else:
    choose(0,0)
    print(ans)