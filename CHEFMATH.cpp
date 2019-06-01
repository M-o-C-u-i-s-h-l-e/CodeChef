#include <bits/stdc++.h>
using namespace std;

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

long long mod = 1e9 + 7;
vector<long long> chef(45);

int solve(long long x, int k, int n) {
    if (k == 0)
        return (x == 0);
    if (x == 0 || n == 0)
        return 0;
    else {
        int total = solve(x, k, n-1);
        if (x >= chef[n-1] && x <= k * chef[n-1])
            total += solve(x - chef[n-1], k - 1, n);
        return total;
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

    chef[0] = 1, chef[1] = 2;
    for (int i = 2; i < 45; i++)
        chef[i] = chef[i-1] + chef[i-2];

    int t;
    scanInt(t);
    while (t--) {
        int x, k;
        scanInt(x);
        scanInt(k);
        printInt(solve(x, k, 43) % mod);
        putchar_unlocked('\n');
    }
}
