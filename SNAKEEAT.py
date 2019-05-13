# O (q log n)
import bisect as bs

for _ in range(int(input())):
	n, q = map(int, input().split())
	ls = list(map(int, input().split()))
	ls.sort()
	Sum = [0] * n
	Sum[0] = ls[0]
	for i in range(1, n):
		Sum[i] = Sum[i-1] + ls[i]
	for __ in range(q):
		k = int(input())
		pos = bs.bisect_left(ls, k)
		l, r = 0, pos
		while l < r:
			m = l + (r - l) // 2
			need = k * (pos - m) - (Sum[pos-1] - Sum[m-1])
			if need <= m:
				r = m
			else:
				l = m + 1
		print(n - r)



# O ((n + q) log n)
for _ in range(int(input())):
	n, q = map(int, input().split())
	ls = [0] + list(map(int, input().split()))
	Q = [[int(input()), i] for i in range(q)]
	ans = [0] * q
	ls.sort()
	Q.sort()
	prev, prevSum, cur, i = 0, 0, 0, 1
	while cur < q:
		F = Q[cur][0]
		while i <= n and ls[i] < F:
			prevSum += (F - ls[i])
			i += 1
		i -= 1
		while prevSum > prev:
			prev += 1
			prevSum -= (F - ls[prev])
		ans[Q[cur][1]] = n - prev
		if cur < q - 1:
			prevSum = prevSum + (i - prev) * (Q[cur+1][0] - F)
		i += 1
		cur += 1
	print(*ans, sep = "\n")
