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

	int n, Count = 0;
	cin >> n;
	vector<long> a(n), b(n), c(n), d(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	vector<long> x(n*n), y(n*n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			x[Count] = a[i] + b[j], y[Count++] = c[i] + d[j];
	sort(y.begin(), y.end());
	long long ans = 0;
	for (int i = 0; i < Count; i++)
		ans += (upper_bound(y.begin(), y.end(), -x[i]) - lower_bound(y.begin(), y.end(), -x[i]));
	cout << ans << endl;
}
