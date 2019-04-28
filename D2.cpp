#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

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
    	int n, ans = 0;
    	cin >> n;
    	vector<int> v(n);
    	for (int i = 0; i < n; i++)
    		cin >> v[i];
    	for (int i = 0; i < n-1; i++) {
    		vector<int> temp;
    		temp.push_back(v[0]);
    		for (int j = 0; j < n; j++) {
    			if (v[j] < temp[0])
    				temp[0] = v[j];
    			else if (v[j] > temp[temp.size()-1])
    				temp.push_back(v[j]);
    			else {
    				auto itr = upper_bound(temp.begin(), temp.end(), v[j]);
    				*itr = v[j];
    			}
    		}
    		ans = max(ans, (int)temp.size());
    		v.push_back(v[0]);
    		v.erase(v.begin());
    	}
    	cout << ans << endl;
    }
}
