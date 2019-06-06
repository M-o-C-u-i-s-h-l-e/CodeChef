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

	int n, k, p;
	cin >> n >> k >> p;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	map<int, int, greater<int>> m;
	for (int i = 0; i < n; i++)
		m[v[i]] = -1;
	auto itr = m.begin(), it = m.begin();
	itr->second = itr->first;
	for (++itr; itr != m.end(); itr++, it++)
		itr->second = (it->first - itr->first <= k) ? it->second : itr->first;
	for (int i = 0, a, b; i < p; i++) {
		cin >> a >> b;
		int start = min(v[a-1], v[b-1]), end = max(v[a-1], v[b-1]);
		(end <= m[start]) ? cout << "Yes\n" : cout << "No\n";
	}
}
