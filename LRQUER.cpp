#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
long N;

int nextPowerOf2(int n) {
	int x = 1;
	while (x < n)
		x <<= 1;
	return x;
}

vector<multiset<long>> createSegTree(vector<long> &input) {
	vector<multiset<long>> segTree(N << 1);
	for (int i = 1; i < input.size(); i++)
		segTree[N + i].insert(input[i]);
	for (int i = N - 1; i > 0; i--) {
		for (int x : segTree[i << 1])
			segTree[i].insert(x);
		for (int x : segTree[i << 1 | 1])
			segTree[i].insert(x);
	}
	return segTree;
}

void check(multiset<long> &m, int key, long &res) {
	auto itr = m.lower_bound(key);
	if (itr == m.end())
		itr--;
	if (abs(*itr - key) < abs(res - key))
		res = *itr;
	if (itr != m.begin())
		itr--;
	if (abs(*itr - key) < abs(res - key))
		res = *itr;
}

int query(vector<multiset<long>> &segTree, int i, int j, int key) {
	long res = 1e10;
	for (i += N, j += N; i <= j; i = (i + 1) >> 1, j = (j - 1) >> 1) {
		if ((i & 1) == 1)
			check(segTree[i], key, res);
		if ((j & 1) == 0)
			check(segTree[j], key, res);
	}
	return res;
}

void update(vector<multiset<long>> &segTree, int i, int val, int prev) {
	for (i += N; i > 0; i >>= 1) {
		auto itr = segTree[i].find(prev);
		segTree[i].erase(itr);
		segTree[i].insert(val);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		N = nextPowerOf2(n + 1);
		vector<long> v(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			v[i] <<= 1;
		}
		vector<multiset<long>> segTree = createSegTree(v);
		while (q--) {
			int ty, x, y;
			cin >> ty >> x >> y;
			if (ty == 1) {
				long res = query(segTree, x, y, (v[x] + v[y]) >> 1);
				res = ((res - v[x]) * (v[y] - res)) >> 2;
				cout << res << endl;
			} else {
				y <<= 1;
				update(segTree, x, y, v[x]);
				v[x] = y;
			}
		}
	}
}
