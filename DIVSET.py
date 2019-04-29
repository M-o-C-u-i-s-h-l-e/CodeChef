def check(x):
	l1 = [ls[i] for i in range(x)]
	pos = x
	for i in range(1, k):
		for j in range(x):
			while pos < n and ls[pos] < c * l1[j]:
				pos += 1
			if pos >= n:
				return False
			l1[j] = ls[pos]
			pos += 1
	return True

for _ in range(int(input())):
	n, k, c = map(int, input().split())
	ls = sorted(list(map(int, input().split())))
	l, r = 0, n
	while r - l > 1:
		m = l + (r - l) // 2
		if check(m):
			l = m
		else:
			r = m
	print(l)
