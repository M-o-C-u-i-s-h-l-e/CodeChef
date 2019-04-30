#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

long long n, W, L;
vector<long long> h, r;

bool solve(long long x) {
	long long temp = W;
	for (int i = 0; i < n; i++) {
		long long ht = h[i] + r[i] * x;
		if (ht >= L) {
			temp -= ht;
			if (temp <= 0)
				return true;
		}
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> W >> L;
	h.resize(n);
	r.resize(n);
	for (int i = 0; i < n; i++)
		cin >> h[i] >> r[i];
	long long l = 0, r = 1e18, ans = LONG_MAX;
	while (l <= r) {
		long long m = l + (r - l) / 2;
		if (solve(m)) {
			ans = min(ans, m);
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << ans << endl;
}
