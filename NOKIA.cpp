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

vector<int> mem(32, -1);

int findMin(int x) {
    if (x <= 0)
        return 0;
    if (mem[x] != -1)
        return mem[x];
    return mem[x] = x + 1 + findMin(x/2) + findMin(x - 1 - x/2);
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
        int Max = (((n+1) * (n+2)) / 2) - 1;
        int Min = findMin(n);
        if (Min <= m && Max >= m) {
            printInt(0);
        } else if (m > Max) {
            printInt(m - Max);
        } else {
            printInt(-1);
        }
        putchar_unlocked('\n');
    }
}
