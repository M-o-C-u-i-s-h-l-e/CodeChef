#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;
    cin >> a >> b;
    int c = a - b;
    if (c % 10 == 9) {
        cout << c - 1 << endl;
    } else {
        cout << c + 1 << endl;
    }
}
