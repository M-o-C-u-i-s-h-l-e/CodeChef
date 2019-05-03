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
		int n;
		cin >> n;
		vector<long> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		long c, d, s;
		cin >> c >> d >> s;
		long Max = *max_element(v.begin(), v.end());
		long ans = Max * (c - 1);
		cout << ans << endl;
	}
}
