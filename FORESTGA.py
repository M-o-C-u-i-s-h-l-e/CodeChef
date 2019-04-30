def solve(x):
	temp = w
	for h, r in ls:
		ht = h + r * x
		if ht >= l:
			temp -= ht
			if temp <= 0:
				return True
	return False

n, w, l = map(int, input().split())
ls = []
for _ in range(n):
	h, r = map(int, input().split())
	ls.append((h, r))
L, R = -1, 10 ** 18 + 1
while R - L > 1:
	M = L + (R - L) // 2
	if solve(M):
		R = M
	else:
		L = M
print(R)
