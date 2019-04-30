#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
long long Max = pow(3141, 5);

long long __sqrt(long long x) {
	long long n = sqrt(x);
	while (n * n <= x)	n++;
	while (n * n > x)	n--;
	return n;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	vector<long long> ls;
	for (long long i = 2; i*i*i <= Max; i++) {
		long long x = i * i * i;
		while (x <= Max) {
			long long sq = __sqrt(x);
			if (sq * sq != x)
				ls.emplace_back(x);
			if (1.0 * x - 0.5 > (1.0 * Max) / i / i)
				break;
			x *= i * i;
		}
	}
	sort(ls.begin(), ls.end());
	ls.erase(unique(ls.begin(), ls.end()), ls.end());

	long long n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		long long sq = max(2LL, __sqrt(x));
		if (sq * sq == x || binary_search(ls.begin(), ls.end(), x)) {
			long long ans = sq -1 + (upper_bound(ls.begin(), ls.end(), x) - ls.begin());
			cout << ans;
		} else {
			x = x + 1 - (max(0LL, __sqrt(x)-1) + (upper_bound(ls.begin(), ls.end(), x) - ls.begin()));
			long long l = 1, r = 2, ans = 0;
			while (true) {
				ans++;
				if (x == r)	break;
				if (x > r)
					r *= 2;
				else {
					l = r / 2;
					break;
				}
			}
			if (r != x) {
				while (l <= r) {
					ans++;
					long long m = l + (r - l) / 2;
					if (m == x)	break;
					(m < x) ? l = m : r = m;
				}
			}
			cout << ans;
		}
		(n) ? cout << " " : cout << endl;
	}
}
