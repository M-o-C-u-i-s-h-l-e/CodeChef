#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

long long mod = 1e9+7;
long long arr[1807][307][10];

long long solve(long long r, long long b, long long l) {
	if (b == 0)
		return (r == 0 && l >= 0) ? 1 : 0;
	if (l < 0 || r < 0)
		return 0;
	if (arr[r][b][l] != -1)
		return arr[r][b][l];
	long long ans = 0;
	ans += solve(r-0, b-1, l);
	ans %= mod;
	ans += solve(r-0, b-1, l-1);
	ans %= mod;
	ans += solve(r-4, b-1, l);
	ans %= mod;
	ans += solve(r-6, b-1, l);
	ans %= mod;
	return arr[r][b][l] = ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	for (int i = 0; i <= 1800; i++)
		for (int j = 0; j <= 300; j++)
			for (int k = 0; k <= 9; k++)
				arr[i][j][k] = -1;
	int t;
	cin >> t;
	while (t--) {
		long r, b, l;
		cin >> r >> b >> l;
		if (r > 1800 || r & 1) {
			cout << 0 << endl;
		} else {
			cout << solve(r, b, l) << endl;
		}
	}
}
