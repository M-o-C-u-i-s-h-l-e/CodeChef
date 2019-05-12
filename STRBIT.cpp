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
		int n, k, Count = 0, state = 0;
		cin >> n >> k;
		string str;
		cin >> str;
		vector<bool> flag(n+1, false);
		for (int i = 0; i < n; i++) {
			if (flag[i])
				state ^= 0 ^ 1;
			if ((state == 0 && str[i] == 'R') || (state == 1 && str[i] == 'G')) {
				flag[min(n, i+k)] = true;
				state ^= 0 ^ 1;
				Count++;
			}
		}
		cout << Count << endl;
	}
}
