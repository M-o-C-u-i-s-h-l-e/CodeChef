for _ in range(int(input())):
	n, k, q = map(int, input().split())
	s = input()
	s = [int(s[i]) for i in range(n)]
	Count = [0, 0]
	j = 0
	L = [0] * n
	R = [0] * n
	for i in range(n):
		while j < n and Count[s[j]] + 1 <= k:
			Count[s[j]] += 1
			j += 1
		L[i] = j - 1
		Count[s[i]] -= 1
	Count[0] = Count[1] = 0
	j = n-1
	for i in range(n-1, -1, -1):
		while j >= 0 and Count[s[j]] + 1 <= k:
			Count[s[j]] += 1
			j -= 1
		R[i] = j + 1
		Count[s[i]] -= 1
	Sum = [0] * (n+1)
	for i in range(n):
		Sum[i+1] = Sum[i] + L[i]
	for __ in range(q):
		li, ri = map(int, input().split())
		li -= 1
		ri -= 1
		k = R[ri] - 1
		res = 0
		if li <= k:
			res += Sum[k+1] - Sum[li] + (ri - k) * ri
			res -= (li + ri - 2) * (ri - li + 1) // 2
		else:
			res += (ri - li + 2) * (ri - li + 1) // 2
		print(res)
