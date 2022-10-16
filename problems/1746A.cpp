#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

typedef long long ll;

void solve() {
	int n, k;
	cin >> n >> k;
	int one = 0, zero = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp) one++;
		else zero++;
	}
	cout << (one ? "YES" : "NO");
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
