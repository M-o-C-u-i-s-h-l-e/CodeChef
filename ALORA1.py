for _ in range(int(input())):
	n = int(input())
	ls = list(map(int, input().split()))
	d = dict()
	flag = True
	for i in range(n):
		if ls[i] not in d.keys():
			d[ls[i]] = 1
		else:
			d[ls[i]] += 1
		if d[ls[i]] > 1:
			flag = False
	print("no") if flag else print("yes")
