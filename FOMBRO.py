for _ in range(int(input())):
	n, mod, q = map(int, input().split())
	ls = [0] * n
	ls[1] = n
	for i in range(2, n):
		ls[1] = (ls[1] * i) % mod
	n += 1
	if n % 2:
		num, den, cur = n // 2 + 1, n // 2, n // 2 + 1
	else:
		num, den, cur = n // 2, n // 2, 1
	n -= 1
	ls[den] = cur
	num += 1
	den -= 1
	while den > 1:
		cur = (cur * (den + 1)) % mod
		cur = (cur * num) % mod
		ls[den] = cur
		num += 1
		den -= 1
	for i in range(2, n//2+1):
		ls[i] = (ls[i] * ls[i-1]) % mod
	for __ in range(q):
		x = int(input())
		if x > n / 2:
			x = n - x
		print(ls[x])
