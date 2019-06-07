#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

long n, x;
vector<long> arr;
vector<vector<long>> g;
vector<bool> visited;

long dfs(int node) {
	visited[node] = true;
	long sum = arr[node];
	for (int i : g[node])
		if (!visited[i])
			sum += dfs(i);
	return max(sum, -x);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		arr.clear(), g.clear(), visited.clear();
		arr.resize(n+1), g.resize(n+1);
		visited.resize(n+1, false);
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			g[i].clear();
		}
		for (int i = 0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		long ans = dfs(1);
		cout << ans << endl;
	}
}
