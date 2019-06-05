#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long mod = 1e9+7;

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
		int n, k;
		cin >> n >> k;
		long long g[n+1];
		g[0] = 1, g[1] = 0;
		for (int i = 2; i <= n; i++)
			g[i] = ((k-1) * g[i-1] + k * g[i-2]) % mod;
		cout << g[n] << endl;
	}
}
