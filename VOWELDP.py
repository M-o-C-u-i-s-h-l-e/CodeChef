from collections import Counter
mod = int(1e9+7)

def nCr(n, r):
	res = [1] + [0] * (r)
	for i in range(1, n+1):
		for j in range(min(i, r), 0, -1):
			res[j] = (res[j] + res[j-1]) % mod
	return res[r]

for _ in range(int(input())):
	ls = list(map(int, input().split()))
	d = {'a': ls[0], 'e': ls[1], 'i': ls[2], 'o': ls[3], 'u': ls[4]};
	st = input()
	Count = Counter(st)
	ans = 1
	for i in Count.keys():
		if i in d.keys() and d[i] > Count[i]:
			ans = (ans * nCr(d[i]-1, Count[i]-1)) % mod
	print(ans)
