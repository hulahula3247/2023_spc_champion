import sys; input = sys.stdin.readline
MIS = lambda: map(int, input().split())
II = lambda: int(input())

def c1(x):
    return x*(x-1)

def c2(x):
    return x-1

N, M = MIS()
ans = [0]*N
pv = 1

while c1(pv) + c2(pv) < M: pv += 1
for i in range(c2(pv)):
    ans[-1-i] = 1

M -= c2(pv)
idx = 0
while M > pv:
    ans[idx] = pv
    M -= pv
    idx += 1
ans[idx] = M
print(*ans)
