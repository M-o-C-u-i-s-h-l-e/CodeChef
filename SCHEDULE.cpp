#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

bool solve(int x, priority_queue<int> pq, int k) {
	int v = pq.top();
	while (k > 0 && !pq.empty()) {
		v = pq.top();
		pq.pop();
		if (v > x)
			k -= (v / (x + 1));
	}
	if (pq.empty() && k >= 0)	return true;
	if (!pq.empty() && pq.top() > x)	return false;
	if (v / (v / (x + 1) + 1) <= x && k >= 0)	return true;
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

	int t;
	cin >> t;
	while (t--) {
		priority_queue<int> pq;
		int n, k, Count = 0;
		string str;
		cin >> n >> k >> str;
		int Count1 = 0, Count2 = 0;
		for (int i = 0; i < n; i++) {
			int x = str[i] - '0';
			(x != i % 2) ? Count1++ : Count2++;
			if (i == 0) {
				Count = 1;
			} else {
				if (str[i-1] == str[i]) {
					Count++;
				} else {
					pq.push(Count);
					Count = 1;
				}
			}
		}
		if (min(Count1, Count2) <= k) {
			cout << 1 << endl;
			continue;
		}
		pq.push(Count);
		int ans = pq.top();
		if (ans == 2 || k == 0) {
			cout << ans << endl;
			continue;
		}
		int l = max(pq.top() / (k+1) - 1, 2), r = n, res = INT_MAX;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (solve(m, pq, k)) {
				res = min(res, m);
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		cout << res << endl;
	}
}
