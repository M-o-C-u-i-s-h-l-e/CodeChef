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
        vector<int> v(n), ans;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            scanInt(v[i]);
            m[v[i]]++;
        }
        if(n == 1) {
            cout << v[0] << endl;
        } else if(n == 2) {
            sort(v.begin(), v.end());
            cout << v[1] << " " << v[0] << '\n';
        } else {
            sort(v.begin(), v.end());
            if(v[0] == 0 && v[1] == 0) {
                if(m[0] == n) {
                    for(int i = 0; i < n; i++)
                        cout << 0 << " ";
                    cout << endl;
                } else {
                    cout << -1 << endl;
                }
            } else {
                m[v[0]]--, m[v[1]]--;
                int first = v[0], second = v[1];
                ans.emplace_back(first);
                ans.emplace_back(second);
                for(int i = 2; i < n; i++) {
                    int third = second + __gcd(first, second);
                    if(m.find(third) == m.end())
                        break;
                    m[third]--;
                    first = second;
                    second = third;
                    ans.emplace_back(third);
                }
                int Count=0, num;
                for(auto itr = m.begin(); itr != m.end(); itr++) {
                    if(itr->second == 1)
                        num = itr->first;
                    Count += itr->second;
                }
                if(Count > 1) {
                    cout << "-1\n";
                } else if(Count == 1) {
                    if(__gcd(num, ans[0]) + ans[0] == ans[1]) {
                        cout << num << " ";
                        for(int i = 0; i < ans.size(); i++)
                            cout << ans[i] << " ";
                        cout << endl;
                    } else {
                        cout << "-1\n";
                    }
                } else {
                    if(__gcd(ans[ans.size()-1], ans[0]) + ans[0] == ans[1]) {
                        cout << ans[ans.size()-1] << " ";
                        for(int i = 0; i < ans.size()-1; i++)
                            cout << ans[i] << " ";
                        cout << endl;
                    } else {
                        for(int i = 0; i < v.size(); i++)
                            cout << ans[i] << " ";
                        cout << endl;
                    }
                }                
            }
        }
    }
}





// Another Solution

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
        int n, index1, index;
        scanInt(n);
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            scanInt(v[i]);
        sort(v.begin(), v.end());
        bool flag = true;
        for (int i = 2; i < n; i++) {
            if (v[i] != (v[i-1] + __gcd(v[i-1], v[i-2]))) {
                flag = false;
                index1 = v[i];
                break;
            }
        }
        if (flag) {
            index = v.back();
            v.pop_back();
            v.insert(v.begin(), index);
            flag = true;
            for (int i = 2; i < n; i++) {
                if (v[i] != (v[i-1] + __gcd(v[i-1], v[i-2]))) {
                    index = v[0];
                    v.erase(v.begin());
                    v.emplace_back(index);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < n; i++)
                if (v[i] == index1) {
                    v.erase(v.begin() + i);
                    break;
                }
            v.insert(v.begin(), index1);
            flag = true;
            for (int i = 2; i < n; i++) {
                if (v[i] != (v[i-1] + __gcd(v[i-1], v[i-2]))) {
                    flag = false;
                    break;
                }
            }
        }
        if (n < 3)
            sort(v.begin(), v.end(), greater<int>());
        if (!flag) {
            printInt(-1);
        } else {
            for (int i = 0; i < n; i++) {
                printInt(v[i]);
                putchar_unlocked(' ');
            }
        }
        putchar_unlocked('\n');
    }
}
