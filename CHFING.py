mod = int(1e9 + 7)

for _ in range(int(input())):
	n, k = map(int, input().split())
	ans = k - 1
	if n < k:
		k = k - n
		n -= 1
		times = k // n
		ans += k + (k * times) - (n * ((times * (times + 1)) // 2))
	print(ans % mod)
