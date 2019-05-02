#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
long long mod = 1e9+9;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	long long arr[1000001];
	arr[0] = arr[1] = 0;
	arr[2] = arr[3] = 1;
	for (int i = 4; i <= 1000000; i++)
		arr[i] = (arr[i-2] + arr[i-3]) % mod;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << arr[n] << endl;
	}
}
