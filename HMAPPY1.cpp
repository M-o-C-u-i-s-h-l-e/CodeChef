#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

class node {
public:
    int Max, Pre, Suf;
    bool hasZero;
    node() {
        this->Max = 0;
        this->Pre = 0;
        this->Suf = 0;
        this->hasZero = true;
    }
};

node null;

int nextPowerOf2(int n) {
    int x = 1;
    while (n > x)
        x <<= 1;
    return x;
}

node merge(node n1, node n2) {
    node temp;
    if (n1.hasZero && n2.hasZero) {
        temp.Max = max(max(n1.Max, n2.Max), n1.Suf + n2.Pre);
        temp.Pre = n1.Pre;
        temp.Suf = n2.Suf;
        temp.hasZero = true;
    } else if (n1.hasZero) {
        temp.Max = max(n1.Max, n1.Suf + n2.Max);
        temp.Pre = n1.Pre;
        temp.Suf = n1.Suf + n2.Max;
        temp.hasZero = true;
    } else if (n2.hasZero) {
        temp.Max = max(n1.Max + n2.Pre, n2.Max);
        temp.Pre = n1.Max + n2.Pre;
        temp.Suf = n2.Suf;
        temp.hasZero = true;
    } else {
        temp.Max = n1.Max + n2.Max;
        temp.Pre = n1.Max + n2.Max;
        temp.Suf = n1.Max + n2.Max;
        temp.hasZero = false;
    }
    return temp;
}

void construct(vector<node> &segTree, vector<int> &input, int low, int high, int pos) {
    if (low == high) {
        segTree[pos].Max = input[low];
        segTree[pos].Pre = input[low];
        segTree[pos].Suf = input[low];
        segTree[pos].hasZero = (input[low] == 1) ? false : true;
        return;
    }
    int mid = (low + high) / 2;
    construct(segTree, input, low, mid, 2 * pos + 1);
    construct(segTree, input, mid + 1, high, 2 * pos + 2);
    segTree[pos] = merge(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

vector<node> createSegTree(vector<int> &input) {
    int n = nextPowerOf2(input.size());
    vector<node> segTree(2 * n - 1);
    construct(segTree, input, 0, input.size() - 1, 0);
    return segTree;
}

node query(vector<node> &segTree, int low, int high, int qLow, int qHigh, int pos) {
    if (qHigh < low || qLow > high || qLow > qHigh)
        return null;
    if (qLow == low && qHigh == high)
        return segTree[pos];
    int mid = (low + high) / 2;
    node n1 = query(segTree, low, mid, qLow, min(mid, qHigh), 2 * pos + 1);
    node n2 = query(segTree, mid + 1, high, max(mid + 1, qLow), qHigh, 2 * pos + 2);
    return merge(n1, n2);
}

/* 
// Another Method to do Query
node query(vector<node> &segTree, int low, int high, int qLow, int qHigh, int pos) {
    if (qHigh < low || qLow > high)
        return null;
    if (qLow <= low && qHigh >= high)
        return segTree[pos];
    int mid = (low + high) / 2;
    node n1 = query(segTree, low, mid, qLow, qHigh, 2 * pos + 1);
    node n2 = query(segTree, mid + 1, high, qLow, qHigh, 2 * pos + 2);
    return merge(n1, n2);
} 
*/

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, k;
    cin >> n >> q >> k;
    vector<int> v(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i + n] = v[i];
    }
    string str;
    cin >> str;
    vector<node> segTree = createSegTree(v);
    int sz = nextPowerOf2(2 * n);
    int start = n, end = start + n - 1;
    for (int i = 0; i < q; i++) {
        if (str[i] == '!') {
            start--, end--;
            if (start == 0)
                start = n, end = start + n - 1;
        } else {
            node ans = query(segTree, 0, 2 * n - 1, start, end, 0);
            cout << min(k, ans.Max) << endl;
        }
    }
}
