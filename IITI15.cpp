#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second

void update(vector<int> &BITree, int pos, int val, int n) {
	while (pos <= n) {
		BITree[pos] += val;
		pos += (pos & -pos);
	}
}

int query(vector<int> &BITree, int pos) {
	int sum = 0;
	while (pos) {
		sum += BITree[pos];
		pos -= (pos & -pos);
	}
	return sum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	cin >> n;
	vector<long> v(n+1), temp(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		temp[i] = v[i];
	}
	sort(v.begin()+1, v.end());
	map<long, int> mp;
	for (int i = 1, idx = 1; i <= n; i++)
		if (!mp.count(v[i]))
			mp[v[i]] = idx++;
	for (int i = 1; i <= n; i++)
		v[i] = mp[temp[i]];
	cin >> q;
	vector<pair<int, pair<int, int>>> Q(q);
	for (int i = 0; i < q; i++) {
		cin >> Q[i].S.F >> Q[i].S.S;
		Q[i].F = i;
	}
	int blockSz = ceil(sqrt(n));
	sort(Q.begin(), Q.end(), [&](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
		int t1 = a.S.F / blockSz;
		int t2 = b.S.F / blockSz;
		if (t1 != t2)
			return t1 < t2;
		return a.S.S < b.S.S;
	});
	vector<int> BITree(n+1, 0), ans(q);
	int st = 1, end = 0, val = 0;
	for (int i = 0; i < q; i++) {
		while (st < Q[i].S.F) {
			val -= query(BITree, v[st] - 1);
			update(BITree, v[st], -1, n);
			st++;
		}
		while (st > Q[i].S.F) {
			st--;
			val += query(BITree, v[st] - 1);
			update(BITree, v[st], 1, n);
		}
		while (end < Q[i].S.S) {
			end++;
			val += query(BITree, n) - query(BITree, v[end]);
			update(BITree, v[end], 1, n);
		}
		while (end > Q[i].S.S) {
			val -= query(BITree, n) - query(BITree, v[end]);
			update(BITree, v[end], -1, n);
			end--;
		}
		ans[Q[i].F] = val;
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << endl;
}
