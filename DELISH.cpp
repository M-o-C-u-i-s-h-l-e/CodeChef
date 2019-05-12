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
		vector<long long> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		vector<long long> minLeft(n), minRight(n), maxLeft(n), maxRight(n);
		minLeft[0] = maxLeft[0] = v[0];
		for (int i = 1; i < n; i++) {
			minLeft[i] = min(minLeft[i-1] + v[i], v[i]);
			maxLeft[i] = max(maxLeft[i-1] + v[i], v[i]);
		}
		minRight[n-1] = maxRight[n-1] = v[n-1];
		for (int i = n-2; i >= 0; i--) {
			minRight[i] = min(minRight[i+1] + v[i], v[i]);
			maxRight[i] = max(maxRight[i+1] + v[i], v[i]);
		}
		long long ans = 0;
		for (int i = 0; i < n-1; i++) {
			ans = max(ans, abs(minLeft[i] - maxRight[i+1]));
			ans = max(ans, abs(maxLeft[i] - minRight[i+1]));
		}
		cout << ans << endl;
	}
}
