#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

bool solve(vector<string> v, int l, int k) {
	for (string i : v)
		if (i.size() > l)
			k -= i.size() / (l + 1);
	return (k < 0) ? false : true;
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
		int n, k;
		string str;
		cin >> n >> k >> str;
		vector<string> v;
		string prev = "";
		prev += str[0];
		for (int i = 1; i < n; i++) {
			if (str[i] != prev[prev.size()-1])
				v.push_back(prev), prev = str[i];
			else
				prev += str[i];
		}
		v.push_back(prev);
		string s1 = "", s2 = "";
		for (int i = 0; i < n; i++) {
			s1 += (i%2 == 0) ? '0' : '1';
			s2 += (i%2 == 0) ? '1' : '0';
		}
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			if (s1[i] != str[i])	a++;
			if (s2[i] != str[i])	b++;
		}
		if (min(a, b) <= k) {
			cout << 1 << endl;
		} else {
			int l = 2, r = n, res = n;
			while (l <= r) {
				int m = l + (r - l) / 2;
				if (solve(v, m, k)) {
					res = min(res, m);
					r = m - 1;
				} else {
					l = m + 1;
				}
			}
			cout << res << endl;
		}
	}
}
