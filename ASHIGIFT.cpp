#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define F first
#define S second
#define ll long long

vector<pair<pair<ll, bool>, pair<ll, ll>>> v;

bool possible(ll n) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].F.S)
			n -= v[i].S.F;
		else if (n >= v[i].S.F)
			n += v[i].S.S;
	}
	return n > 0;
}

long long solve(ll l, ll r, ll ans) {
	while (l <= r) {
		ll m = l + (r - l) / 2;
		if (possible(m)) {
			ans = min(ans, m);
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	return ans;
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
		v.clear();
		long long d, req = 1;
		cin >> d;
		int b;
		cin >> b;
		for (int i = 0; i < b; i++) {
			ll x, y;
			cin >> x >> y;
			req += y;
			v.push_back({{x, true}, {y, 0}});
		}
		int c;
		cin >> c;
		for (int i = 0; i < c; i++) {
			ll p, q, r;
			cin >> p >> q >> r;
			v.push_back({{p, false}, {q, r}});
		}
		sort(v.begin(), v.end());
		cout << solve(1, req, req) << endl;
	}
}
