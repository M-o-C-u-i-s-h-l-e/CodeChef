def gcd(a, b):
	return a if b == 0 else gcd(b, a % b)

def func(i, cur_gcd):
	if i == n:
		return 1 if cur_gcd == 1 else 0
	key = (i, cur_gcd)
	if key in d.keys():
		return d[key]
	d[key] = func(i+1, cur_gcd) + func(i+1, gcd(cur_gcd, ls[i]))
	return d[key]

for _ in range(int(input())):
	n, res = int(input()), 0
	ls = list(map(int, input().split()))
	d = {}
	for i in range(n):
		res += func(i+1, ls[i])
	print(res)
