def q1(x, y, d):
	print(1, x, y, d)
	s = input()
	return s == "Yes"

def q2(x, y):
	print(2, x, y)
	s = input()
	return s == "Yes"

def solve(ls, val):
	if len(ls) == 1:
		return ls
	if len(ls) == 2:
		if not q2(ls[0], ls[1]):
			ls[0], ls[1] = ls[1], ls[0]
		return ls
	a, b = list(), list()
	a.append(ls[0])
	for i in range(1, len(ls)):
		if q1(ls[0], ls[i], val):
			a.append(ls[i])
		else:
			b.append(ls[i])
	a = solve(a, val << 1)
	b = solve(b, val << 1)
	if q2(a[0], b[0]):
		i = j = 0
		for k in range(len(ls)):
			if k & 1:
				ls[k] = b[i]
				i += 1
			else:
				ls[k] = a[j]
				j += 1
	else:
		i = j = 0
		for k in range(len(ls)):
			if k & 1:
				ls[k] = a[i]
				i += 1
			else:
				ls[k] = b[j]
				j += 1
	return ls

for _ in range(int(input())):
	n = int(input())
	ls = [i + 1 for i in range(n)]
	ls = solve(ls, 2)
	ans = [0] * n
	for i in range(n):
		ans[ls[i]-1] = i + 1
	print("3 ", end = "")
	print(*ans, sep = ' ')
