#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

int n;

bool valid(vector<char>& c) {
	stack<char> seq;
	for (int i = 0; i < n; i++) {
		if (c[i] == '(') {
			seq.push('(');
		} else {
			if (!seq.empty()) seq.pop();
			else return false;
		}
	}
	return seq.empty();
}

void solve() {
	string s;
	cin >> s;
	n = (int)s.size();

	int lcnt = 0, rcnt = 0;
	for (int i = 0; i < n; i++) {
		if (s.at(i) == '(') lcnt++;
		if (s.at(i) == ')') rcnt++;
	}
	int needl = max(0, rcnt - lcnt) + (n - lcnt - rcnt - abs(lcnt - rcnt)) / 2;
	vector<char> choosel(n);
	for (int i = 0; i < n; i++) {
		if (s.at(i) == '?') {
			if (needl > 0) {
				choosel[i] = '(';
				needl--;
			} else {
				choosel[i] = ')';
			}
		} else {
			choosel[i] = s.at(i);
		}
	}
	if (!valid(choosel)) {
		cout << "NO\n";
		return;
	}
	// replace highest index ( with ) and lowest index ) with (
	bool changedl = false, changedr = false;
	int temp;
	for (int i = n - 1; i >= 0; i--) {
		if (choosel[i] == '(' && s.at(i) == '?') {
			choosel[i] = ')';
			temp = i;
			changedl = true;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (choosel[i] == ')' && s.at(i) == '?' && i != temp) {
			choosel[i] = '(';
			changedr = true;
			break;
		}
	}
	cout << (valid(choosel) && changedl && changedr ? "NO" : "YES") << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) solve();
	return 0;
}
