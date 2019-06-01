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

void multiply(long long f1[2][2], long long f2[2][2], long long m) {
    long long a = (f1[0][0] * f2[0][0] + f1[0][1] * f2[1][0]) % m;
    long long b = (f1[0][0] * f2[0][1] + f1[0][1] * f2[1][1]) % m;
    long long c = (f1[1][0] * f2[0][0] + f1[1][1] * f2[1][0]) % m;
    long long d = (f1[1][0] * f2[0][1] + f1[1][1] * f2[1][1]) % m;
    f1[0][0] = a, f1[0][1] = b, f1[1][0] = c, f1[1][1] = d;
}

void pow(long long f[2][2], long long n, long long m) {
    if (n < 2)
        return;
    pow(f, n/2, m);
    multiply(f, f, m);
    if (n & 1) {
        long long f1[2][2] = {1, 1, 1, 0};
        multiply(f, f1, m);
    }
}

long long fast_fib(long long n, long long m) {
    long long f[2][2] = {1, 1, 1, 0};
    pow(f, n-1, m);
    return f[0][0];
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
        int n, m;
        scanInt(n);
        scanInt(m);
        printInt((2 * fast_fib(n, m)) % m);
        putchar_unlocked('\n');
    }
}
