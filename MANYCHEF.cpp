#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		for (int i = str.size()-4; i >= 0; i--)
			if ((str[i] == 'C' || str[i] == '?') && (str[i+1] == 'H' || str[i+1] == '?') && (str[i+2] == 'E' || str[i+2] == '?') && (str[i+3] == 'F' || str[i+3] == '?'))
				str[i] = 'C', str[i+1] = 'H', str[i+2] = 'E', str[i+3] = 'F';
		for (int i = 0; i < str.size(); i++)
			if (str[i] == '?')
				str[i] = 'A';
		cout << str << endl;
	}
}
