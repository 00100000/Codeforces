#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout<<(#x)<<": "<<(x)<<endl
#define dbglp(x) cout<<(#x)<<":"<<endl;for(auto z:x)cout<<z<<" ";cout<<endl
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];

	ll ans = 0;
	for (int i = 1; i < n - 1; i += 2) ans += max(0, max(h[i - 1], h[i + 1]) - h[i] + 1);

	if (n % 2 == 0) {
		// progressively shift max buildings one spot to the right, starting from the back
		ll temp = ans;
		for (int i = n - 2; i >= 2; i -= 2) {
			temp -= max(0, max(h[i - 2], h[i]) - h[i - 1] + 1);
			temp += max(0, max(h[i - 1], h[i + 1]) - h[i] + 1);
			ans = min(ans, temp);
		}
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) solve();
	return 0;
}
