import bisect as bs

n, ans = int(input()), 0
A = []
B = []
C = []
D = []
for i in range(n):
	a, b, c, d = map(int, input().split())
	A.append(a)
	B.append(b)
	C.append(c)
	D.append(d)
X = [a+b for a in A for b in B]
Y = [c+d for c in C for d in D]
Y.sort()
for x in X:
	ans += (bs.bisect_right(Y, -x) - bs.bisect_left(Y, -x))
print(ans)
