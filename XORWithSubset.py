for _ in range(int(input())):
	n, k = map(int, input().split())
	ls = list(map(int, input().split()))
	dp = [False] * 1024
	dp[0] = True
	for i in range(n):
		for j in range(1024):
			dp[j ^ ls[i]] = dp[j ^ ls[i]] | dp[j]
	dp = [i ^ k for i in range(1024) if dp[i]]
	print(max(dp))
