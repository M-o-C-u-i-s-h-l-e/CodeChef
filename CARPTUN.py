for _ in range(int(input())):
	n = int(input())
	ls = list(map(int, input().split()))
	c, d, s = map(int, input().split())
	print(max(ls) * (c-1))
