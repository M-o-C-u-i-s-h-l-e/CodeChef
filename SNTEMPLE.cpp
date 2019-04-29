#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

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
		long long n, sum = 0;
		cin >> n;
		vector<long long> v(n+2, 0), l(n+2, 0), r(n+2, 0);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			sum += v[i];
		}
		for (int i = 1; i <= n; i++)
			l[i] = min(l[i-1] + 1, v[i]);
		for (int i = n; i >= 1; i--)
			r[i] = min(r[i+1] + 1, v[i]);
		long long Max = 0;
		for (int i = 1; i <= n; i++)
			Max = max(Max, min(l[i], r[i]));
		long long ans = sum - Max * Max;
		cout << ans << endl;
	}
}
