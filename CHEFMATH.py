def solve(x, k, n):
	if k == 0:
		if x == 0:
			return 1
		else:
			return 0
	elif x == 0 or n == 0:
		return 0
	else:
		total = solve(x, k, n-1)
		if x >= chef[n-1] and x <= k * chef[n-1]:
			total += solve(x - chef[n-1], k - 1, n)
		return total

mod = int(1e9 + 7)
chef = [0] * 45
chef[0], chef[1] = 1, 2
for i in range(2, 45):
	chef[i] = chef[i-1] + chef[i-2]

for _ in range(int(input())):
	x, k = map(int, input().split())
	print(solve(x, k, 43) % mod)
