#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

void solve() {
	string t;
	cin >> t;
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];

	vector<pair<int, int>> steps;
	vector<bool> red((int)t.size());
	for (int i = 0; i < (int)t.size(); i++) {
		if (!red[i]) {
			int maxIncr = 0, maxIncrInd = 0, jInd = 0;
			// try overlaying every string in every position from i to i - 9
			for (int j = max(0, i - 9); j <= i; j++) {
				for (int k = 0; k < n; k++) {
					// check if it can be overlayed there
					bool valid = true;
					int l = 0;
					for (int m = j; l < (int)s[k].size() && m < (int)t.size(); l++, m++) {
						if (s[k].at(l) != t.at(m)) {
							valid = false;
							break;
						}
					}
					// valid overlaying
					if (valid && l == (int)s[k].size()) {
						if (maxIncr < j + l - i) {
							maxIncr = j + l - i;
							maxIncrInd = k;
							jInd = j;
						}
					}
				}
			}
			// impossible to fill in any more
			if (maxIncr == 0) {
				cout << -1 << "\n";
				return;
			}

			int goal = i + maxIncr;
			while (i < goal) {
				red[i] = true;
				i++;
			}
			i--;
			steps.push_back({maxIncrInd + 1, jInd + 1});
		}
	}
	cout << steps.size() << "\n";
	for (int i = 0; i < (int)steps.size(); i++) {
		cout << steps[i].first << " " << steps[i].second << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	while (q-- > 0) solve();
	return 0;
}
