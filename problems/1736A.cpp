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
	vector<int> b(n);
	int zeroCntA = 0;
	int oneCntA = 0;
	int zeroCntB = 0;
	int oneCntB = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) zeroCntA++;
		else oneCntA++;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (b[i] == 0) zeroCntB++;
		else oneCntB++;
	}
	int minOps = max(0, zeroCntB - zeroCntA) + max(0, oneCntB - oneCntA);
	int cnt = 0;
	for (int i = 0; i < n; i++) if (a[i] != b[i]) cnt++;
	cout << (minOps == cnt ? minOps : minOps + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) {
		solve();
		cout << "\n";
	}
	return 0;
}
