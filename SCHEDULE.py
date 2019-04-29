def solve(ls, l, k):
	for i in ls:
		p = len(i)
		if p > l:
			k -= p // (l + 1)
	if k < 0:
		return False
	return True

for _ in range(int(input())):
	n, k = map(int, input().split())
	st = input()
	ls = list()
	prev = st[0]
	for i in st[1:]:
		if i != prev[-1]:
			ls.append(prev)
			prev = i
		else:
			prev += i
	ls.append(prev)
	s1 = '10' * (n // 2)
	s2 = '01' * (n // 2)
	if n%2 != 0:
		s1 += '1'
		s2 += '0'
	a = b = 0
	for i in range(n):
		if s1[i] != st[i]:
			a += 1
		if s2[i] != st[i]:
			b += 1
	if min(a, b) <= k:
		print(1)
	else:
		l, r, res = 2, n, n
		while l <= r:
			m = l + (r - l) // 2
			if solve(ls, m, k):
				res = min(res, m)
				r = m - 1
			else:
				l = m + 1
		print(res)
