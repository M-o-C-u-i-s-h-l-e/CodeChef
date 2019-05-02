mod = int(1e9+9)

ls = [0] * 1000001
ls[0] = ls[1] = 0
ls[2] = ls[3] = 1
for i in range(4, 1000001):
	ls[i] = (ls[i-2] + ls[i-3]) % mod
for _ in range(int(input())):
	print(ls[int(input())])
