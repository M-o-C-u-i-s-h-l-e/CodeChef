#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

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
		int n, m;
		cin >> n >> m;
		vector<vector<long long>> cost(n), disc(n), dp(n);
		for (int i = 0; i < n; i++) {
			dp[i].resize(m);
			cost[i].resize(m);
			disc[i].resize(m);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> cost[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> disc[i][j];
		for (int i = 0; i < m; i++)
			dp[0][i] = cost[0][i];
		for (int i = 1; i < n; i++) {
			long long prev = *min_element(dp[i-1].begin(), dp[i-1].end());
			for (int j = 0; j < m; j++) {
				long long d = max(0LL, cost[i][j] - disc[i-1][j]);
				dp[i][j] = min(dp[i-1][j] + d, prev + cost[i][j]);
			}
		}
		cout << *min_element(dp[n-1].begin(), dp[n-1].end()) << endl;
	}
}
