#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

typedef long long ll;

void solve() {
	ll n;
	string s;
	cin >> n >> s;
	// prefix sums
	vector<ll> a(n + 1);
	for (ll i = 0; i < n; i++) a[i + 1] = a[i] + s.at(i) - '0';
	// a[r] - a[l] = r - l
	// a[r] - r = a[l] - l
	map<ll, ll> m;
	// simplifies problem to a[i] = a[i]
	for (ll i = 0; i < n + 1; i++) m[a[i] - i]++;
	ll cnt = 0;
	for (auto i : m) {
		// map[a[i] - i] choose 2
		cnt += (i.second * (i.second - 1)) / 2;
	}

	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}
	return 0;
}
