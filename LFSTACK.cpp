#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

template<typename T>
void scanInt(T &x) {
    bool neg = false;
    register int c = getchar_unlocked();
    x = 0;
    for (; (c < 48 || c > 57) && (c != '-'); c = getchar_unlocked());
    if (c == '-') {
        neg = true;
        c = getchar_unlocked();
    }
    for (; c > 47 && c < 58; c = getchar_unlocked())
        x = (x << 1) + (x << 3) + c - 48;
    if (neg)
        x *= -1;
}

template<typename T>
void printInt(T n) {
    if (n < 0){
        n = -n;
        putchar_unlocked('-');
    }
    int i = 21;
    char output_buffer[21];
    do {
        output_buffer[--i] = (n % 10) + '0';
        n /= 10;
    } while (n);
    do {
        putchar_unlocked(output_buffer[i]);
    } while (++i < 21);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    int t;
    scanInt(t);
    while (t--) {
        int n, total = 0;
        scanInt(n);
        vector<int> sz(n);
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++) {
            scanInt(sz[i]);
            total += sz[i];
            v[i].resize(sz[i]);
            for (int j = 0; j < sz[i]; j++)
                scanInt(v[i][j]);
        }
        vector<int> q(total);
        for (int i = total -1; i >= 0; i--)
            scanInt(q[i]);
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int start = 0, end = sz[i];
            for (int j = 0; j < total && start < end; j++)
                if (v[i][start] == q[j])
                    start++;
            if (start < end) {
                flag = false;
                break;
            }
        }
        (flag) ? cout << "Yes\n" : cout << "No\n";
    }
}
