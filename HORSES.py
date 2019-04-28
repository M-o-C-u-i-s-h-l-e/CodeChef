t = int(input())
while t:
	t -= 1
	n = int(input())
	ls = sorted(list(map(int, input().split())))
	ans = 1e11
	for i in range(n-1):
		ans = min(ls[i+1] - ls[i], ans)
	print(ans)
