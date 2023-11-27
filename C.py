import sys; input = sys.stdin.readline
MIS = lambda: map(int, input().split())
II = lambda: int(input())

N = II()
pf = [0]*360
for _ in range(N):
    a, b = MIS()
    for i in range(180+a-b, 180+a+b+1):
        pf[i%360] += 1
print(360-pf.count(0))

#블레이즈는 직사각형으로 나가요!
