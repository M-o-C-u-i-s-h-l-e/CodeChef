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
		int n, ans = 0;
		cin >> n;
		vector<string> str(n);
		for (int i = 0; i < n; i++)
			cin >> str[i];
		vector<bool> x(n, true), y(n, true);
		for (int i = n-1; i >= 0; i--)
			for (int j = n-1; j >= 0; j--) {
				if (str[i][j] == '#')
					x[i] = y[j] = false;
				else if (x[i] && y[j])
					ans++;
			}
		cout << ans << endl;
	}
}
