#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 2);
	vector<int> b(n + 1);
	a[0] = 1;
	a[n + 1] = 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < n + 1; i++) b[i] = lcm(a[i], a[i + 1]);
	for (int i = 0; i < n; i++) {
		if (a[i + 1] != gcd(b[i], b[i + 1])) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) {
		solve();
		cout << '\n';
	}
	return 0;
}
