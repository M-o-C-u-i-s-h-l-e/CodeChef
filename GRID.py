for _ in range(int(input())):
	n = int(input())
	ls = [input() for i in range(n)]
	x = [True] * n
	y = [True] * n
	ans = 0
	for i in range(n-1, -1, -1):
		for j in range(n-1, -1, -1):
			if ls[i][j] == "#":
				x[i] = False
				y[j] = False
			elif x[i] and y[j]:
				ans += 1
	print(ans)
