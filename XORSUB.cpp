#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
    	int n, k, ans = 0;
    	cin >> n >> k;
    	vector<int> v(n);
    	for (int i = 0; i < n; i++)
    		cin >> v[i];
    	vector<bool> dp(1024, false);
    	dp[0] = true;
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < 1024; j++)
    			dp[j ^ v[i]] = dp[j ^ v[i]] | dp[j];
    	for (int i = 0; i < 1024; i++)
    		if (dp[i])
    			ans = max(ans, k ^ i);
    	cout << ans << endl;
    }
}
