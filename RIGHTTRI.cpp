#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(6);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		double h, s;
		cin >> h >> s;
		if (h * h < 4 * s) {
			cout << -1 << endl;
			continue;
		}
		double a = sqrt(h * h + 4 * s);
		double b = sqrt(h * h - 4 * s);
		cout << fixed << (a - b) / 2.0 << " " << (a + b) / 2.0 << " " << h << endl;
	}
}
