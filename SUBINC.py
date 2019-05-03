for _ in range(int(input())):
	n = int(input())
	ls = list(map(int, input().split()))
	ans, i = 0, 0
	while i < n:
		temp, Count = ls[i], 0
		while i < n and ls[i] >= temp:
			temp = ls[i]
			i += 1
			Count += 1
		ans += (Count * (Count - 1)) // 2
	print(ans + n)
