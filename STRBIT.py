for _ in range(int(input())):
	n, k = map(int, input().split())
	st = input()
	Count = state = 0
	flag = [False] * (n+1)
	for i in range(n):
		if flag[i]:
			state ^= 0 ^ 1
		if (state == 0 and st[i] == 'R') or (state == 1 and st[i] == 'G'):
			flag[min(n, i+k)] = True
			state ^= 0 ^ 1
			Count += 1
	print(Count)
