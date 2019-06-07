#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool q1(int x, int y, int d) {
    cout << 1 << ' ' << x << ' ' << y << ' ' << d << endl;
    string s;
    cin >> s;
    return s == "Yes";
}

bool q2(int x, int y) {
    cout << 2 << ' ' << x << ' ' << y << endl;
    string s;
    cin >> s;
    return s == "Yes";
}

vector<int> solve(vector<int> v, int val) {
    if (v.size() == 1)
        return v;
    if (v.size() == 2) {
        if (!q2(v[0], v[1]))
            swap(v[0], v[1]);
        return v;
    }
    vector<int> a, b;
    a.push_back(v[0]);
    for (int i = 1; i < (int)v.size(); i++)
        q1(v[0], v[i], val) ? a.push_back(v[i]) : b.push_back(v[i]);
    a = solve(a, val << 1);
    b = solve(b, val << 1);
    if (q2(a[0], b[0])) {
        for (int k = 0, i = 0, j = 0; k < v.size(); k++)
            v[k] = (k & 1) ? b[i++] : a[j++];
    } else {
        for (int k = 0, i = 0, j = 0; k < v.size(); k++)
            v[k] = (k & 1) ? a[i++] : b[j++];
    }
    return v;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n), ans(n);
        for (int i = 0; i < n; i++)
            v[i] = i + 1;
        v = solve(v, 2);
        for (int i = 0; i < n; i++)
            ans[v[i]-1] = i + 1;
        cout << "3 ";
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
}
