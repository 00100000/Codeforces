#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int j = 0; j < n; j++) cin >> a[j];

		vector<bool> str(m);
		int one, two;
		for (int j = 0; j < n; j++) {
			one = a[j] - 1;
			two = m - a[j];
			if (one > two) {
				int temp = one;
				one = two;
				two = temp;
			}
			if (!str[one]) {
				str[one] = true;
			} else {
				str[two] = true;
			}
		}
		for (int j = 0; j < m; j++) cout << (str[j] ? 'A' : 'B');
		cout << "\n";
	}

	return 0;
}
