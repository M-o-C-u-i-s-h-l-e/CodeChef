import sys
sys.setrecursionlimit(100010)

for _ in range(int(input())):
	n, x = map(int, input().split())
	ls = list(map(int, input().split()))
	v = [False] * (n+1)
	adj = [list() for i in range(n+1)]
	for _ in range(n-1):
		i, j = map(int, input().split())
		adj[i].append(j)
		adj[j].append(i)

	def dfs(node):
		v[node] = True
		Sum = ls[node-1]
		for i in adj[node]:
			if not v[i]:
				Sum += dfs(i)
		return max(Sum, -x)
	
	print(dfs(1))
