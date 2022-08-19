#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	// optimal solution will always have iq at the lowest value at the end
	// so starting from the back, always choose to test the contest until
	// you reach the original iq
	vector<bool> ans(n);
	int bwq = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (bwq == q) {
			for (int j = i; j >= 0; j--) {
				if (a[j] <= bwq) ans[j] = true;
			}
			break;
		}
		ans[i] = true;
		if (a[i] > bwq) bwq++;
	}
	for (int i = 0; i < n; i++) cout << ans[i];
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) solve();
	return 0;
}
