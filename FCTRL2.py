for _ in range(int(input())):
	n = int(input())
	pro = 1
	for i in range(2, n+1):
		pro *= i
	print(pro)
