import sys; input = sys.stdin.readline
MIS = lambda: map(int, input().split())
II = lambda: int(input())
MOD = int(1e9)+7

N, M = MIS()
B = []
for _ in range(N):
    a, b = MIS()
    B.append(b)

dp = [[0]*2 for _ in range(N+1)]
dp[0] = [1, 0]
for i in range(N):
    if B[i] == 0:
        dp[i+1][0] = dp[i][0]
        dp[i+1][1] = dp[i][0]*(M-1) + dp[i][1]
    else:
        dp[i+1][0] = dp[i][0]*(M-1)
        dp[i+1][1] = dp[i][0] + dp[i][1]*(M-1)
    dp[i+1][0] %= MOD
    dp[i+1][1] %= MOD

print(sum(dp[-1])%MOD)
