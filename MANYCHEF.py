for _ in range(int(input())):
	st = list(input())
	for i in range(len(st)-4, -1, -1):
		if ((st[i] == 'C' or st[i] == '?') and (st[i+1] == 'H' or st[i+1] == '?') and (st[i+2] == 'E' or st[i+2] == '?') and (st[i+3] == 'F' or st[i+3] == '?')):
			st[i], st[i+1], st[i+2], st[i+3] = 'C', 'H', 'E', 'F'
	for i in range(len(st)):
		if st[i] == '?':
			st[i] = 'A'
	print(*st, sep = "")
