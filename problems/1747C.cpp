#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

void solve() {
	int n;
	cin >> n;
	// if a_1 is not the smallest, Alice can always force Bob to decrease it to 0
	// otherwise, Bob can force Alice to decrease a_1 to zero
	int first;
	cin >> first;
	int minA = INT_MAX;
	for (int i = 0; i < n - 1; i++) {
		int temp;
		cin >> temp;
		minA = min(minA, temp);
	}
	if (first > minA) cout << "Alice";
	else cout << "Bob";
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
