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
		string s1, s2;
		cin >> s1 >> s2;
		int n = s1.size();
		vector<int> v1(n), v2(n);
		v1[0] = (s1[0] == '.') ? 0 : 1e7;
		v2[0] = (s2[0] == '.') ? 0 : 1e7;
		for (int i = 1; i < n; i++) {
			v1[i] = (s1[i] == '.') ? min(v1[i-1], v2[i-1] + 1) : 1e7;
			v2[i] = (s2[i] == '.') ? min(v2[i-1], v1[i-1] + 1) : 1e7;
		}
		int ans = min(v1[n-1], v2[n-1]);
		(ans < 1e7) ? cout << "Yes\n" << ans << endl : cout << "No\n";
	}
}
