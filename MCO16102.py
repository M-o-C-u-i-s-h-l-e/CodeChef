mod = int(1e9+7)

n = int(input())
ls = list(map(int, input().split()))
dp = [0] * n
dp[0] = 2
for i in range(1, n):
	dp[i] = dp[i-1]
	if ls[i-1] <= ls[i]:
		dp[i] += dp[i-1]
	else:
		dp[i] += dp[i-2] if i > 1 else 1
	dp[i] %= mod
print(dp[n-1])
