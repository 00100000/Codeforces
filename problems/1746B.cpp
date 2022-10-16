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
	for (int i = 0; i < n; i++) cin >> a[i];
	// add ones from the start to zeroes from the back
	int ops = 0;
	int l = 0, r = n - 1;
	for (; r > l && l < r; r--) {
		if (a[r] == 0) {
			// find first one to add
			for (; l < r; l++) {
				if (a[l] == 1) {
					a[r] = 1;
					a[l] = 0;
					ops++;
					break;
				}
			}
		}
	}
	cout << ops;
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
