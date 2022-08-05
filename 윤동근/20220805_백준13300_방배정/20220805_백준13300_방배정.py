import sys

K,N=map(int,sys.stdin.readline().split())
student_list=[]
cnt=0
for i in range(K):
    student_list.append(tuple(sys.stdin.readline().split()))
for i in set(student_list):
    cnt+=-(-student_list.count(i)//N)
print(cnt)