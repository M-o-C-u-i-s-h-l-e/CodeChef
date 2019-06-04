#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        stack<char> st;
        int Count = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '<') {
                st.push(str[i]);
            } else {
                if (st.empty())
                    break;
                else
                    st.pop();
                if (st.empty())
                    Count = i + 1;
            }
        }
        cout << Count << endl;
    }
}
