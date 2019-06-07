#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long mod = 1e9+7;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<long> v(n), dp(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	dp[0] = 2;
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i-1];
		if (v[i-1] <= v[i]) {
			dp[i] += dp[i-1];
		} else {
			dp[i] += (i > 1) ? dp[i-2] : 1;
		}
		dp[i] %= mod;
	}
	cout << dp[n-1] << endl;
}
