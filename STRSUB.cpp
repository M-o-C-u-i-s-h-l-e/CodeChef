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
		int n, k, q;
		string s;
		cin >> n >> k >> q >> s;
		vector<int> Count(2, 0);
		int j = 0;
		vector<long long> L(n, 0), R(n, 0);
		for (int i = 0; i < n; i++) {
			while (j < n && Count[s[j]-'0'] + 1 <= k)
				Count[s[j++]-'0']++;
			L[i] = j - 1;
			Count[s[i]-'0']--;
		}
		Count[0] = Count[1] = 0;
		j = n - 1;
		for (int i = n-1; i >= 0; i--) {
			while (j >= 0 and Count[s[j]-'0'] + 1 <= k)
				Count[s[j--]-'0']++;
			R[i] = j + 1;
			Count[s[i]-'0']--;
		}
		vector<long long> sum(n+1, 0);
		for (int i = 0; i < n; i++)
			sum[i+1] = sum[i] + L[i];
		while (q--) {
			int li, ri;
			cin >> li >> ri;
			li--, ri--;
			int k = R[ri] - 1;
			long long res;
			if (li <= k) {
				res = sum[k+1] - sum[li] + (long long)(ri - k) * ri;
				res -= (long long)(li + ri - 2) * (ri - li + 1) / 2;
			} else {
				res = (long long)(ri - li + 2) * (ri - li + 1) / 2;
			}
			cout << res << endl;
		}
	}
}
