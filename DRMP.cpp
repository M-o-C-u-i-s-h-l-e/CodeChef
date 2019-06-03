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

long long N, sz;
vector<long long> ans;
vector<pair<long long, int>> v;

void solve(int pos, long long mul) {
    if (pos == sz) {
        ans.emplace_back(mul + N);
        return;
    }
    long long pow = 1;
    for (int i = 0; i <= v[pos].second; i++) {
        if (mul > N / pow)
            break;
        solve(pos + 1, mul * pow);
        pow *= v[pos].first;
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
        long long n;
        scanInt(n);
        N = n;
        for (int i = 2, sq = sqrt(n); i <= sq; i++)
            if (n % i == 0) {
                int Count = 0;
                while (n % i == 0)
                    Count += 2, n /= i;
                v.push_back({i, Count});
            }
        if (n != 1)
            v.push_back({n, 2});
        sz = v.size();
        solve(0, 1);
        sort(ans.begin(), ans.end());
        printInt(ans.size());
        putchar_unlocked('\n');
        for (int i = 0; i < ans.size(); i++) {
            printInt(ans[i]);
            putchar_unlocked('\n');
        }
        v.clear();
        ans.clear();
    }
}
