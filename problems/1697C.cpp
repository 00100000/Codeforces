#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool solve(int n, string s, string t) {
	// you can't move an a to the left, and you can't move a c to the right

	// make sure the a's and c's in s are in the same order as those in string t
	stack<char> ACs;
	ACs.push('.');
	for (int i = 0; i < n; i++) {
		if (t.at(i) != 'b') {
			ACs.push(t.at(i));
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s.at(i) != 'b') {
			if (s.at(i) == ACs.top()) {
				ACs.pop();
			} else {
				return false;
			}
		}
	}
	if (ACs.top() != '.') return false;
	// make sure the a's in string s are always to the left of or at those in string t
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s.at(i) == 'a') cnt++;
		if (t.at(i) == 'a') cnt--;
		if (cnt < 0) return false;
	}
	// do the same for c's
	cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s.at(i) == 'c') cnt++;
		if (t.at(i) == 'c') cnt--;
		if (cnt < 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n;
		string s, t;
		cin >> n >> s >> t;
		cout << (solve(n, s, t) ? "YES" : "NO") << "\n";
	}

	return 0;
}
