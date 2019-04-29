import bisect

for _ in range(int(input())):
	n = int(input())
	ls = list(map(int, input().split()))
	ans = []
	for i in range(n):
		pos = bisect.bisect_right(ans, ls[i], 0, len(ans))
		if pos == len(ans):
			ans.append(ls[i])
		else:
			ans[pos] = ls[i]
	print(len(ans), *ans, sep = " ")
