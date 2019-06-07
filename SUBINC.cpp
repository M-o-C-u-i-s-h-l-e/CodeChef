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
		vector<long> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			long temp = v[i], Count = 0;
			while (i < n && v[i] >= temp)
				temp = v[i++], Count++;
			i--;
			ans += (Count * (Count - 1)) / 2;
		}
		cout << ans + n << endl;
	}
}
