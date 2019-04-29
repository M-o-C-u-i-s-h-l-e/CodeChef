for _ in range(int(input())):
	n, q = map(int, input().split())
	ls = [0] + list(map(int, input().split()))
	Q = [[int(input()), i] for i in range(q)]
	ans = [0] * q
	ls.sort()
	Q.sort()
	prev, prevSum, cur, i = 0, 0, 0, 1
	while cur < q:
		F = Q[cur][0]
		while i <= n and ls[i] < F:
			prevSum += (F - ls[i])
			i += 1
		i -= 1
		while prevSum > prev:
			prev += 1
			prevSum -= (F - ls[prev])
		ans[Q[cur][1]] = n - prev
		if cur < q - 1:
			prevSum = prevSum + (i - prev) * (Q[cur+1][0] - F)
		i += 1
		cur += 1
	print(*ans, sep = "\n")
