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
		int n;
		cin >> n;
		vector<long long> v(n), l(n), r(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		long long cur = 0, res = INT_MIN, minPrefix = 0, minSuffix = 0;
		for (int i = 0; i < n; i++) {
			cur += v[i];
			l[i] = cur - minPrefix;
			res = max(res, l[i]);
			minPrefix = min(minPrefix, cur);
		}
		cur = 0;
		for (int i = n-1; i >= 0; i--) {
			cur += v[i];
			r[i] = cur - minSuffix;
			minSuffix = min(minSuffix, cur);
		}
		for (int i = 0; i < n; i++) {
			long long temp = 0;
			if (i > 0)
				temp += l[i-1];
			if (i < n-1)
				temp += r[i+1];
			res = max(res, temp);
		}
		cout << res << endl;
	}
}
