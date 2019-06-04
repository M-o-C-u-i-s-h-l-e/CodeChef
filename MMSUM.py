for _ in range(int(input())):
	n = int(input())
	ls = list(map(int, input().split()))
	l = [0] * n
	r = [0] * n
	cur, res, minPrefix, minSuffix = 0, -10000000000, 0, 0
	for i in range(n):
		cur += ls[i]
		l[i] = cur - minPrefix
		res = max(res, l[i])
		minPrefix = min(minPrefix, cur)
	cur = 0
	for i in range(n-1, -1, -1):
		cur += ls[i]
		r[i] = cur - minSuffix
		minSuffix = min(minSuffix, cur)
	for i in range(n):
		temp = 0
		if i > 0:
			temp += l[i-1]
		if i < n-1:
			temp += r[i+1]
		res = max(res, temp)
	print(res)
