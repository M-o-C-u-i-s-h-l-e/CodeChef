#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        long ans = INT_MAX;
        for (int i = 0; i < n-1; i++)
            ans = min(ans, v[i+1] - v[i]);
        cout << ans << endl;
    }
}
