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
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			long x;
			cin >> x;
			auto itr = upper_bound(v.begin(), v.end(), x);
			if (itr == v.end())
				v.push_back(x);
			else
				*itr = x;
		}
		cout << v.size() << " ";
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
	}
}
