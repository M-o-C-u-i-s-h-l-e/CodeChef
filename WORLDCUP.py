def solve(r, b, l):
	if b == 0:
		if r == 0 and l >= 0:
			return 1
		return 0
	if l < 0 or r < 0:
		return 0
	if arr[r][b][l] != -1:
		return arr[r][b][l]
	ans = 0
	ans += solve(r-0, b-1, l)
	ans %= mod
	ans += solve(r-0, b-1, l-1)
	ans %= mod
	ans += solve(r-4, b-1, l)
	ans %= mod
	ans += solve(r-6, b-1, l)
	ans %= mod
	arr[r][b][l] = ans
	return ans

mod = int(1e9+7)
arr = [[[-1 for k in range(10)] for j in range(301)] for i in range(1801)]
for _ in range(int(input())):
	r, b, l = map(int, input().split())
	if r > 1800 or r & 1:
		print(0)
	else:
		print(solve(r, b, l))
