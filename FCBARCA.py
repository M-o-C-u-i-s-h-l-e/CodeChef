# O(1)
mod = int(1e9+7)

for _ in range(int(input())):
	n, k = map(int, input().split())
	ans = (k ** n + k * ((-1) ** n)) // (k + 1)
	print(ans % mod)
  
  
  


# O(n)
mod = int(1e9+7)

for _ in range(int(input())):
	n, k = map(int, input().split())
	ls = [0] * (n + 1)
	ls[0], ls[1] = 1, 0
	for i in range(2, n+1):
		ls[i] = ((k-1) * ls[i-1] + k * ls[i-2]) % mod
	print(ls[n])
