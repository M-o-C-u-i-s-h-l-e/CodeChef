from math import sqrt

def solve(pos, mul):
	if pos == sz:
		ans.append(mul + N)
		return
	__pow = 1
	for i in range(ls[pos][1] + 1):
		if mul > N // __pow:
			break
		solve(pos + 1, mul * __pow)
		__pow *= ls[pos][0]

for _ in range(int(input())):
	n = int(input())
	N, sq = n, int(sqrt(n))
	ls = list()
	ans = list()
	for i in range(2, sq+1):
		if n % i == 0:
			Count = 0
			while n % i == 0:
				Count += 2
				n //= i
			ls.append([i, Count])
	if n != 1:
		ls.append([n, 2])
	sz = len(ls)
	solve(0, 1)
	ans.sort()
	print(len(ans))
	print(*ans, sep = '\n')
