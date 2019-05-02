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

	int t;
	cin >> t;
	while (t--) {
		int n, mod, q;
		cin >> n >> mod >> q;
		vector<long long> v(n);
		v[1] = n;
		for (int i = 2; i < n; i++)
			v[1] = (v[1] * i) % mod;
		long long num, den, cur;
		n++;
		if (n % 2)
			num = n / 2 + 1, den = n / 2, cur = n / 2 + 1;
		else
			num = n / 2, den = n / 2, cur = 1;
		n--;
		v[den] = cur;
		num++, den--;
		while (den > 1) {
			cur = (cur * (den + 1)) % mod;
			cur = (cur * num) % mod;
			v[den] = cur;
			num++, den--;
		}
		for (int i = 2; i <= n/2; i++)
			v[i] = (v[i] * v[i-1]) % mod;
		while (q--) {
			int x;
			cin >> x;
			if (x > n/2)	x = n - x;
			cout << v[x] << endl;
		}
	}
}
