#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long mod = 1e9+7;

long long nCr(int n, int r) {
	vector<long long> res(r+1, 0);
	res[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = min(i, r); j > 0; j--)
			res[j] = (res[j] + res[j-1]) % mod;
	return res[r];
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
		map<char, int> m, Count;
		cin >> m['a'] >> m['e'] >> m['i'] >> m['o'] >> m['u'];
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
			Count[str[i]]++;
		long long ans = 1;
		for (auto itr = Count.begin(); itr != Count.end(); itr++)
			if (m[itr->first] > itr->second)
				ans = (ans%mod * nCr(m[itr->first]-1, itr->second-1)%mod) % mod;
		cout << ans << endl;
	}
}
