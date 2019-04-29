for _ in range(int(input())):
	n, m = map(int, input().split())
	a = sorted(list(map(int, input().split())))
	b = sorted(list(map(int, input().split())))
	ls = list()
	for i in range(n):
		end = min(n, 10001 // (i+1))
		for j in range(end):
			ls.append(a[i] + b[j])
	ls.sort()
	for i in range(m):
		print(ls[int(input())-1])
