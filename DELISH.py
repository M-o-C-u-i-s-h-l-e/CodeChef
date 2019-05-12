for _ in range(int(input())):
	n = int(input())
	ls = list(map(int, input().split()))
	minLeft = [0] * n
	maxLeft = [0] * n
	minRight = [0] * n
	maxRight = [0] * n
	minLeft[0] = maxLeft[0] = ls[0]
	for i in range(1, n):
		minLeft[i] = min(minLeft[i-1] + ls[i], ls[i])
		maxLeft[i] = max(maxLeft[i-1] + ls[i], ls[i])
	minRight[n-1] = maxRight[n-1] = ls[n-1]
	for i in range(n-2, -1, -1):
		minRight[i] = min(minRight[i+1] + ls[i], ls[i])
		maxRight[i] = max(maxRight[i+1] + ls[i], ls[i])
	ans = 0
	for i in range(n-1):
		ans = max(ans, abs(minLeft[i] - maxRight[i+1]))
		ans = max(ans, abs(maxLeft[i] - minRight[i+1]))
	print(ans)
