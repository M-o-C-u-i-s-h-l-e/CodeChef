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

	long j, s, m;
	cin >> j >> s >> m;
	long ans = (m - j) / s;
	(!(ans&1)) ? cout << "Lucky Chef\n" : cout << "Unlucky Chef\n";
}
