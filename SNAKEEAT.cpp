// O (q log n)
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
		int n, q;
		cin >> n >> q;
		vector<long> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		vector<long long> sum(n);
		sum[0] = v[0];
		for (int i = 1; i < n; i++)
			sum[i] = sum[i-1] + v[i];
		while (q--) {
			long k;
			cin >> k;
			int pos = lower_bound(v.begin(), v.end(), k) - v.begin();
			int l = 0, r = pos;
			while (l < r) {
				int m = l + (r - l) / 2;
				long long need = k * (pos - m) - (sum[pos-1] - sum[m-1]);
				if (need <= m)
					r = m;
				else
					l = m + 1;
			}
			cout << n - r << endl;
		}
	}
}



// O ((n + q) * log n)
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
		int n, q;
		cin >> n >> q;
		vector<long long> v(n+1), ans(q);
		vector<pair<long long, int>> Q(q);
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		for (int i = 0; i < q; i++) {
			cin >> Q[i].first;
			Q[i].second = i;
		}
		sort(v.begin(), v.end());
		sort(Q.begin(), Q.end());
		long long prev = 0, preSum = 0;
		for (int i = 1, cur = 0; cur < q; i++, cur++) {
			long long F = Q[cur].first;
			while (v[i] < F && i <= n)
				preSum += (F - v[i++]);
			i--;
			while (preSum > prev)
				prev++, preSum -= (F - v[prev]);
			ans[Q[cur].second] = n - prev;
			if (cur < q - 1)
				preSum = preSum + (i - prev) * (Q[cur+1].first - F);
		}
		for (int i = 0; i < q; i++)
			cout << ans[i] << endl;
	}
}
