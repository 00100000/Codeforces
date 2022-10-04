#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int biggest = a[0] * 2 - 1;
	int cnt = 0;
	for (int i = 0; i < n; i++) cnt += max(0, a[i] / biggest + (a[i] % biggest > 0 ? 1 : 0) - 1);
	cout << cnt << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) solve();
	return 0;
}
