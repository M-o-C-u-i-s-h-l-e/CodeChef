#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 100000

long segTree[3][4 * MAX];
bool plant[3][4 * MAX];

void updateUtil(int pos, int low, int high, int dim) {
    if (plant[dim][pos]) {
        segTree[dim][pos] = (high - low + 1) - segTree[dim][pos];
        if (low ^ high) {
            plant[dim][2 * pos + 1] ^= true;
            plant[dim][2 * pos + 2] ^= true;
        }
        plant[dim][pos] = false;
    }
}

void update(int pos, int low, int high, int qLow, int qHigh, int dim) {
    updateUtil(pos, low, high, dim);
    if (low > qHigh || high < qLow)
        return;
    if (low >= qLow && high <= qHigh) {
        plant[dim][pos] = true;
        updateUtil(pos, low, high, dim);
        return;
    }
    int mid = (low + high) >> 1;
    update(2 * pos + 1, low, mid, qLow, qHigh, dim);
    update(2 * pos + 2, mid + 1, high, qLow, qHigh, dim);
    segTree[dim][pos] = segTree[dim][2 * pos + 1] + segTree[dim][2 * pos + 2];
}

long query(int pos, int low, int high, int qLow, int qHigh, int dim) {
    updateUtil(pos, low, high, dim);
    if (low > qHigh || high < qLow)
        return 0;
    if (low >= qLow && high <= qHigh)
        return segTree[dim][pos];
    int mid = (low + high) >> 1;
    return (query(2 * pos + 1, low, mid, qLow, qHigh, dim) + query(2 * pos + 2, mid + 1, high, qLow, qHigh, dim));
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        memset(segTree, 0, sizeof(segTree));
        memset(plant, false, sizeof(plant));
        int n, d[3];
        cin >> d[0] >> d[1] >> d[2] >> n;
        while (n--) {
            int ty, x1, y1, z1, x2, y2, z2;
            cin >> ty;
            if (ty != 3) {
                cin >> x1 >> x2;
                update(0, 0, d[ty] - 1, x1, x2, ty);
            } else {
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                long x = query(0, 0, d[0] - 1, x1, x2, 0), tx = (x2 - x1 + 1) - x;
                long y = query(0, 0, d[1] - 1, y1, y2, 1), ty = (y2 - y1 + 1) - y;
                long z = query(0, 0, d[2] - 1, z1, z2, 2), tz = (z2 - z1 + 1) - z;
                cout << (x * y * z) + (x * ty * tz) + (tx * y * tz) + (tx * ty * z) << endl;
            }
        }
    }
}
