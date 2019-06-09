#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long mod = 1e9+7;

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

long long fastPow(long long x, long long k) {
    if (k == 0)
        return 1;
    if (k & 1)
        return (x * fastPow((x * x) % mod, k/2)) % mod;
    return (fastPow((x * x) % mod, k/2));
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
        long long k;
        scanInt(k);
        long long ans = fastPow(2, k-1);
        printInt((ans * 10) % mod);
        putchar_unlocked('\n');
    }
}
