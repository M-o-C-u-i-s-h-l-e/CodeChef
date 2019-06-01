mem = [-1] * 32

def findMin(x):
	if x <= 0:
		return 0
	if mem[x] != -1:
		return mem[x]
	mem[x] = x + 1 + findMin(x//2) + findMin(x - 1 - x//2)
	return mem[x]

for _ in range(int(input())):
	n, m = map(int, input().split())
	Max = (((n+1) * (n+2)) // 2) - 1
	Min = findMin(n)
	if Min <= m and Max >= m:
		print(0)
	elif m > Max:
		print(m - Max)
	else:
		print(-1)
