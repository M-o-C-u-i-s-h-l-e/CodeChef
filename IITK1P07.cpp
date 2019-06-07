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

long long multiply(long long a, long long b, long long mod) {
    long long ans = 0;
    while (b) {
        if (b & 1)
            ans = (ans + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ans;
}

long long solve(long long x, long long m, long long mod) {
    if (m == 0)
        return 1;
    if (m == 1)
        return (1 + x) % mod;
    if (m&1) {
        long long temp = solve(multiply(x, x, mod), m/2, mod);
        temp = multiply(temp, (1 + x), mod);
        temp = temp % mod;
        return temp;
    } else {
        long long temp = solve(x, m-1, mod);
        temp = multiply(temp, x, mod);
        temp = (temp + 1) % mod;
        return temp;
    }
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
        long long x, m, n;
        scanInt(x);
        scanInt(m);
        scanInt(n);
        printInt(solve(x, m, n));
        putchar_unlocked('\n');
    }
}
