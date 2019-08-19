#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int> lp(1e6+7, 0);

void pre() {
    lp[1] = 1;
    for (int i = 2; i <= 1e6; i+=2)
        lp[i] = 2;
    for (int i = 3; i <= 1e6; i+=2)
        if (lp[i] == 0)
            for (int j = i; j <= 1e6; j+=i)
                if (lp[j] == 0)
                    lp[j] = i;
}

int nextPowerOf2(int n) {
    if (n == 0)
        return 1;
    if (n & (n - 1) == 0)
        return n;
    while (n & (n - 1) > 0)
        n &= (n - 1);
    return (n << 1);
}

void constructTree(vector<int> &segTree, vector<int> &input, int low, int high, int pos) {
    if (low == high) {
        segTree[pos] = lp[input[low]];
        input[low] /= lp[input[low]];
        return;
    }
    int mid = (low + high) / 2;
    constructTree(segTree, input, low, mid, 2 * pos + 1);
    constructTree(segTree, input, mid + 1, high, 2 * pos + 2);
    segTree[pos] = max(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

vector<int> createSegTree(vector<int> &input) {
    int n = nextPowerOf2(input.size());
    vector<int> segTree(2 * n - 1, 0);
    constructTree(segTree, input, 0, input.size() - 1, 0);
    return segTree;
}

int query(vector<int> &segTree, int low, int high, int qLow, int qHigh, int pos) {
    if (low >= qLow && high <= qHigh)
        return segTree[pos];
    if (low > qHigh || high < qLow)
        return 1;
    int mid = (low + high) / 2;
    return max(query(segTree, low, mid, qLow, qHigh, 2 * pos + 1), query(segTree, mid + 1, high, qLow, qHigh, 2 * pos + 2));
}

void update(vector<int> &segTree, vector<int> &input, int low, int high, int qLow, int qHigh, int pos) {
    if (segTree[pos] == 1 || low > qHigh || high < qLow)
        return;
    if (low == high) {
        segTree[pos] = lp[input[low]];
        input[low] /= lp[input[low]];
        return;
    }
    int mid = (low + high) / 2;
    update(segTree, input, low, mid, qLow, qHigh, 2 * pos + 1);
    update(segTree, input, mid + 1, high, qLow, qHigh, 2 * pos + 2);
    segTree[pos] = max(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pre();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        vector<int> segTree = createSegTree(v);
        while (m--) {
            int ty, l, h;
            cin >> ty >> l >> h;
            if (ty == 0) {
                update(segTree, v, 0, n-1, --l, --h, 0);
            } else {
                cout << query(segTree, 0, n-1, --l, --h, 0) << ' ';
            }
        }
        cout << endl;
    }
}
