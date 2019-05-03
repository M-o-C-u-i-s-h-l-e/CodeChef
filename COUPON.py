for _ in range(int(input())):
	n, m = map(int, input().split())
	cost = [list(map(int, input().split())) for i in range(n)]
	disc = [list(map(int, input().split())) for i in range(n)]
	dp = [[0 for j in range(m)] for i in range(n)]
	for i in range(m):
		dp[0][i] = cost[0][i]
	for i in range(1, n):
		prev = min(dp[i-1])
		for j in range(m):
			d = max(0, cost[i][j] - disc[i-1][j])
			dp[i][j] = min(dp[i-1][j] + d, prev + cost[i][j])
	print(min(dp[n-1]))
