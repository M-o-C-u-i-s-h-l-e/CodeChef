#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
vector<int> v;
map<pair<int, int>, long long> m;

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

long long func(int i, int cur_gcd) {
	if (i == n)
		return (cur_gcd == 1) ? 1 : 0;
	pair<int, int> key = {i, cur_gcd};
	if (m.count(key)) return m[key];
	return m[key] = func(i+1, cur_gcd) + func(i+1, gcd(cur_gcd, v[i]));
}

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
		cin >> n;
		v.resize(n);
		m.clear();
		for (int i = 0; i < n; i++)
			cin >> v[i];
		long long res = 0;
		for (int i = 0; i < n; i++)
			res += func(i+1, v[i]);
		cout << res << endl;
	}
}
