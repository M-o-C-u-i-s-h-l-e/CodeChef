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
        int n;
        scanInt(n);
        bool flag = true;
        map<long, int> m;
        for (long i = 0, x; i < n; i++) {
            scanInt(x);
            m[x]++;
            if (m[x] > 1)
                flag = false;
        }
        (flag) ? cout << "no\n" : cout << "yes\n";
    }
}
