t = int(input())
while t:
	t -= 1
	m, x, y = map(int, input().split())
	flag = [True] * 101
	ls = list(map(int, input().split()))
	for i in range(m):
		start = ls[i] - (x * y)
		end = ls[i] + (x * y)
		if start < 1:
			start = 1
		if end > 100:
			end = 100
		for j in range(start, end+1):
			flag[j] = False
	Count = 0
	for i in range(1, 101):
		if flag[i]:
			Count += 1
	print(Count)
