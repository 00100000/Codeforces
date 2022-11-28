#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

typedef long long ll;

ll MOD = 1e9 + 7;

ll max(ll a, ll b) { return a > b ? a : b; }

ll floorMod(ll x) { return (x % MOD + MOD) % MOD; }
// x^n mod MOD
ll powMod(ll x, ll n) {
	if (n == 0) return 1;
	ll ret = powMod(x, n / 2);
	if (n % 2 == 0) return ret * ret % MOD;
	else return (x * ret % MOD) * ret % MOD;
}

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> freq(n + 1);
	for (ll i = 0; i < n; i++) {
		ll temp;
		cin >> temp;
		freq[temp]++;
	}
	// prefix sum
	for (ll i = 1; i < n + 1; i++) freq[i] += freq[i - 1];

	ll cnt = 0;
	ll overCnt = 0;
	ll mFac = 1;
	for (ll i = 1; i <= m; i++) {
		mFac *= i;
		mFac %= MOD;
	}
	// modular inverse
	ll mFacInv = powMod(mFac, MOD - 2);

	for (ll i = 0, j = k; j <= n; i++, j++) {
		// numbers between i and j choose m
		ll elements = freq[j] - (i > 0 ? freq[i - 1] : 0);
		ll prod = 1;
		ll overProd = 1;
		for (ll l = 0; l < m; l++) {
			prod *= max(1, elements - l);
			prod %= MOD;
		}
		for (ll l = 0; l < m; l++) {
			overProd *= max(1, freq[j] - freq[i] - l);
			overProd %= MOD;
		}
		// essentially compares (not under mod) mFac to prod
		if (m <= elements) {
			cnt += prod * mFacInv % MOD - overCnt;
			cnt = floorMod(cnt);
		}
		if (m <= freq[j] - freq[i]) overCnt = overProd * mFacInv % MOD;
		else overCnt = 0;
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
