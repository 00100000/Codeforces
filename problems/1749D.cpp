#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

typedef long long ll;

int MOD = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m;
	cin >> n >> m;
	// sieve of eratosthenes
	vector<bool> isPrime(n + 1, true);
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}

	// each term up to m should be divisible by the product every prime number below i
	ll total = 0;
	ll unambDigits = 1;
	ll mPow = 1;
	ll divBy = 1;
	for (int i = 0; i < n; i++) {
		if (unambDigits > 0) {
			if (isPrime[i + 1]) divBy *= i + 1;
			unambDigits = (unambDigits % MOD) * ((m / divBy) % MOD);
			unambDigits %= MOD;
		}
		mPow *= m % MOD;
		mPow %= MOD;
		total += mPow - unambDigits;
		total %= MOD;
	}

	cout << total;
	return 0;
}
