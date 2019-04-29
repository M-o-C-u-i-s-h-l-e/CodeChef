def possible(n):
	for i in range(len(ls)):
		if ls[i][0][1]:
			n -= ls[i][1][0]
		elif n >= ls[i][1][0]:
			n += ls[i][1][1]
	return n > 0

def solve(l, r, ans):
	while l <= r:
		m = l + (r - l) // 2
		if possible(m):
			ans = min(ans, m)
			r = m - 1
		else:
			l = m + 1
	return ans

for _ in range(int(input())):
	d = int(input())
	temp = list(map(int, input().split()))
	ls = []
	i = req = 1
	while i < 2*temp[0]:
		ls.append([[temp[i], True], [temp[i+1], 0]])
		req += temp[i+1]
		i += 2
	temp = list(map(int, input().split()))
	i = 1
	while i < 3*temp[0]:
		ls.append([[temp[i], False], [temp[i+1], temp[i+2]]])
		i += 3
	ls.sort()
	print(solve(1, req, req))
