import sys; input = sys.stdin.readline
MIS = lambda: map(int, input().split())
II = lambda: int(input())
from collections import *

N = II()
T = list(MIS())
P = list(MIS())
G = [-1]*3
for i in range(N):
    G[P[i]] = i+1

goal = (T[0], G[1], T[1], G[2])
que = deque()
que.append((100, 1, 100, 2))#t1, x1, t2, x2
dic = defaultdict(int)
dic[(100, 1, 100, 2)] = 1
while que:
    t1, x1, t2, x2 = que.popleft()
    if (t1, x1, t2, x2) == goal: break
    if t1 < T[0] or t2 < T[1]: continue
    s = set([1, 2, 3])
    s.discard(x1)
    s.discard(x2)
    for num in s:
        n1 = (t1-5, num, t2, x2)
        n2 = (t1, x1, t2-5, num)
        if not dic[n1]:
            dic[n1] = dic[(t1, x1, t2, x2)] + 1
            que.append(n1)
        if not dic[n2]:
            dic[n2] = dic[(t1, x1, t2, x2)] + 1
            que.append(n2)

if not dic[goal]:
    print(-1)
    exit(0)

cur = goal
ans = []
while cur != (100, 1, 100, 2):
    t1, x1, t2, x2 = cur
    s = set([1, 2, 3])
    s.discard(x1)
    s.discard(x2)
    for num in s:
        n1 = (t1+5, num, t2, x2)
        n2 = (t1, x1, t2+5, num)
        if dic[n1] == dic[cur]-1:
            ans.append((num, x1))
            cur = n1
        else:
            ans.append((num, x2))
            cur = n2

ans.reverse()
print(len(ans))
for a, b in ans:
    print(a, b)
