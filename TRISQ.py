ls = [0] * 10001
for i in range(4, 10001):
	ls[i] = ls[i-2] + (i - 2) // 2

for _ in range(int(input())):
	n = int(input())
	print(ls[n])

	
	
# Another Solution
for _ in range(int(input())):
	n = int(input()) // 2
	print((n*n - n) // 2)
