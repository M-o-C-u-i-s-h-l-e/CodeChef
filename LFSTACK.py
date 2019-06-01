for _ in range(int(input())):
	n = int(input())
	sz = list()
	ls = list()
	for i in range(n):
		ls.append(list(map(int, input().split())))
		sz.append(ls[i][0])
		ls[i].pop(0)
	q = list(map(int, input().split()))
	for i in q:
		for k in range(n):
			if sz[k] != 0:
				if ls[k][sz[k]-1] == i:
					sz[k] -= 1
	flag = True
	for i in range(n):
		if sz[i] != 0:
			flag = False
			break
	print("Yes") if flag else print("No")
