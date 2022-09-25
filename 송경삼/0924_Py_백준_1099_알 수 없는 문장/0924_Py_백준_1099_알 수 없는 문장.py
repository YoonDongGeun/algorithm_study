def CNT(string):
    sub=dict()
    for c in string:
        if c in sub:
            sub[c]+=1
        else: sub[c]=1
    return sub

WORDS=input()
l=len(WORDS)
N=int(input())
words=[input() for _ in '_'*N]
LENS=[len(word) for word in words]
cnt_words=[ CNT(word) for word in words ]
cnt_WORDS=[[0]*l for _ in '_'*l]

DP=[1<<10]*l

for i in range(l):
    for j in range(len(words)):
        if i+1==LENS[j]:
            if not cnt_WORDS[0][i]:cnt_WORDS[0][i]=CNT(WORDS[:i+1])
            if cnt_WORDS[0][i]==cnt_words[j]:
                sub=LENS[j]
                for x in range(i+1):
                    if WORDS[x]==words[j][x]:sub-=1
                if sub<DP[i]:DP[i]=sub
        elif (i-LENS[j]>=0 and DP[i-LENS[j]]!=1<<10):
            S=i-LENS[j]+1
            if not cnt_WORDS[S][i]:cnt_WORDS[S][i]=CNT(WORDS[S:i+1])
            if cnt_WORDS[S][i]==cnt_words[j]:
                sub=LENS[j]+DP[S-1]
                for x in range(S,i+1):
                    if WORDS[x]==words[j][x-S]:sub-=1
                if sub<DP[i]:DP[i]=sub
print(DP[-1] if DP[-1]!=1<<10 else -1)






