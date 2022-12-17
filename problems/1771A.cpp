#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int maxa = 0, mina = 1e9;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maxa = max(maxa, a[i]);
		mina = min(mina, a[i]);
	}
	ll maxcnt = 0, mincnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == maxa) maxcnt++;
		if (a[i] == mina) mincnt++;
	}
	cout << (maxa == mina ? (maxcnt * (maxcnt - 1)) : maxcnt * mincnt * 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}
	return 0;
}
