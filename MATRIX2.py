n, m = map(int, input().split())
ls = [input() for _ in range(n)]
Count = [0] * m
res = 0
for i in range(n-1, -1, -1):
	for j in range(m):
		Count[j] = Count[j] + 1 if ls[i][j] == '1' else 0
	last = 0
	for j in range(m):
		last = min(last+1, Count[j])
		res += last
print(res)
