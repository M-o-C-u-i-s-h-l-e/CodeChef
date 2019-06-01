def multiply(a, b, mod):
	ans = 0
	while b:
		if b & 1:
			ans = (ans + a) % mod
		a = (a + a) % mod
		b >>= 1
	return ans

def solve(x, m, mod):
	if m == 0:
		return 1
	if m == 1:
		return (1 + x) % mod
	if m & 1:
		temp = solve(multiply(x, x, mod), m//2, mod)
		temp = multiply(temp, (1 + x), mod)
		temp = temp % mod
		return temp
	else:
		temp = solve(x, m-1, mod)
		temp = multiply(temp, x, mod)
		temp = (temp + 1) % mod
		return temp

for _ in range(int(input())):
	x, m, n = map(int, input().split())
	print(solve(x, m, n))
