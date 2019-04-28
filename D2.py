# will gets TLE

import bisect

for _ in range(int(input())):
	n = int(input())
	ls = list(map(int, input().split()))
	ans = 0
	for i in range(n-1):
		temp = list()
		temp.append(ls[0])
		for j in range(n):
			if ls[j] not in temp:
				if ls[j] < temp[0]:
					temp[0] = ls[j]
				else:
					x = bisect.bisect_right(temp, ls[j])
					if x < len(temp):
						temp[x] = ls[j]
					else:
						temp.append(ls[j])
		ans = max(ans, len(temp))
		ls.append(ls[0])
		ls.pop(0)
	print(ans)
