import sys; input = sys.stdin.readline
MIS = lambda: map(int, input().split())
II = lambda: int(input())

N = II()
arr = list(MIS())
Q = II()
for _ in range(Q):
    a, b = MIS()
    idx = []
    v = []
    ans = [-1]*N
    for i in range(N):
        if a <= arr[i] <= b:
            idx.append(i)
            v.append(arr[i])
        else: ans[i] = arr[i]
    v.sort()
    for i in range(len(idx)):
        ans[idx[i]] = v[i]
    print(*ans)
