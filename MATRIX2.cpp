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

	long n, m, res = 0;
	cin >> n >> m;
	vector<string> str(n);
	vector<int> Count(m, 0);
	for (int i = 0; i < n; i++)
		cin >> str[i];
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < m; j++)
			Count[j] = (str[i][j] == '1') ? Count[j] + 1 : 0;
		for (int j = 0, last = 0; j < m; j++)
			res += last = min(last+1, Count[j]);
	}
	cout << res << endl;
}
