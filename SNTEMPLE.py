for _ in range(int(input())):
	n = int(input())
	ls = [0] + list(map(int, input().split())) + [0]
	r = [0] * (n+2)
	l = [0] * (n+2)
	for i in range(1, n+1):
		l[i] = min(l[i-1] + 1, ls[i])
	for i in range(n, 0, -1):
		r[i] = min(r[i+1] + 1, ls[i])
	Max = 0
	for i in range(1, n+1):
		Max = max(Max, min(l[i], r[i]))
	print(sum(ls) - (Max ** 2))
