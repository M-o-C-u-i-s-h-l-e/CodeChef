#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

long long n, k, c;
vector<long long> v;

bool check(long long x) {
	vector<long long> v1, v2;
	for (long long i = 0; i < x; i++)
		v1.push_back(v[i]);
	int pos = x;
	for (int i = 1; i < k; i++) {
		v2.clear();
		for (int j = 0; j < v1.size(); j++) {
			while (pos < n && v[pos] < c * v1[j])
				pos++;
			if (pos >= n)	return false;
			v2.push_back(v[pos++]);
		}
		v1.swap(v2);
	}
	return true;
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
		cin >> n >> k >> c;
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		long long l = 0, r = n + 1;
		while (r - l > 1) {
			int m = l + (r - l) / 2;
			(check(m)) ? l = m : r = m;
		}
		cout << l << endl;
	}
}
