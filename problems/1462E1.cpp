#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

typedef long long ll;

void solve() {
	ll n;
	cin >> n;
	vector<ll> freq(n + 1);
	for (ll i = 0; i < n; i++) {
		ll temp;
		cin >> temp;
		freq[temp]++;
	}
	ll cnt = 0;
	ll a = 0, b = 0;
	for (ll i = 1; i < n - 1; i++) {
		// number of elements in between choose 3
		// minus overcounted subsets already formed by the last iteration
		ll elements = (freq[i] + freq[i + 1] + freq[i + 2]);
		cnt += (elements * (elements - 1) * (elements - 2)) / 6 - ((a + b) * (a + b - 1) * (a + b - 2)) / 6;
		a = freq[i + 1];
		b = freq[i + 2];
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
