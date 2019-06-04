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
		int m, x, y, Count = 0;
		cin >> m >> x >> y;
		vector<bool> v(101, true);
		for (int i = 0, a; i < m; i++) {
			cin >> a;
			int l = (a - (x*y) < 0) ? 1 : (a - (x*y));
			int r = (a + (x*y) > 100) ? 100 : (a + (x*y));
			for (int j = l; j <= r; j++)
				v[j] = false;
		}
		for (int i = 1; i <= 100; i++)
			if (v[i])
				Count++;
		cout << Count << endl;
	}
}
