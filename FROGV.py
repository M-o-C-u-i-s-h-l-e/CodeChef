n, k, p = map(int, input().split())
ls = list(map(int, input().split()))
ls = [[ls[i], i+1] for i in range(n)]
ls.sort()
d = {}
i = 0
while i < n:
	j = i + 1
	d[ls[i][1]] = i
	while j < n and ls[j][0] <= ls[j-1][0] + k:
		d[ls[j][1]] = i
		j += 1
	i = j
for _ in range(p):
	x, y = map(int, input().split())
	print("Yes") if d[x] == d[y] else print("No")
