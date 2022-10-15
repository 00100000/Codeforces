#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a < abs(b - c) + c ? 1 : (a > abs(b - c) + c ? 2 : 3)) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) solve();
	return 0;
}
