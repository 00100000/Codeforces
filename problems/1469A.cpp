#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

void solve() {
	string s;
	cin >> s;
	int n = (int)s.size();

	int lcnt = 0, rcnt = 0;
	for (int i = 0; i < n; i++) {
		if (s.at(i) == '(') lcnt++;
		if (s.at(i) == ')') rcnt++;
	}
	int needl = max(0, rcnt - lcnt) + (n - lcnt - rcnt - abs(lcnt - rcnt)) / 2;

	stack<char> seq;
	for (int i = 0; i < n; i++) {
		if (s.at(i) == '?') {
			if (needl > 0) {
				seq.push('(');
				needl--;
			} else if (!seq.empty()) {
				seq.pop();
			} else {
				cout << "NO\n";
				return;
			}
		} else if (s.at(i) == '(') {
			seq.push('(');
		} else if (s.at(i) == ')') {
			if (!seq.empty()) {
				seq.pop();
			} else {
				cout << "NO\n";
				return;
			}
		}
	}
	if (seq.empty()) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) solve();
	return 0;
}
