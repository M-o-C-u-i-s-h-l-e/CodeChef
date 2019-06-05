#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second

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
		long long N, M, Max = 0;
		cin >> N >> M;
		vector<long long> a(N), b(N), q(M), v;
		for (int i = 0; i < N; i++)
			cin >> a[i];
		for (int i = 0; i < N; i++)
			cin >> b[i];
		for (int i = 0; i < M; i++) {
			cin >> q[i];
			Max = max(Max, q[i]);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		multimap<long long, pair<int, int>> m;
		for (int i = 0; i < N; i++)
			m.insert({a[i]+b[0], {i, 0}});
		while (Max--) {
			auto itr = m.begin();
			v.push_back(itr->F);
			int i = itr->S.F, j = itr->S.S;
			m.erase(m.begin());
			m.insert({a[i]+b[j+1], {i, j+1}});
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < M; i++)
			cout << v[q[i]-1] << endl;
	}
}
