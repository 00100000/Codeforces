#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

void solve() {
	int n;
	cin >> n;
	int even = 0, odd = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		temp % 2 == 0 ? even++ : odd++;
	}
	// cases converge after mod 4
	odd %= 4;
	even %= 2;
	switch (odd) {
		case 3:
			cout << "Alice";
			break;
		case 2:
			cout << "Bob";
			break;
		case 1:
			cout << (even == 1 ? "Alice" : "Bob");
			break;
		case 0:
			cout << "Alice";
			break;
	}
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
