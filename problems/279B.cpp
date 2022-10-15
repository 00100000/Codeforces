#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t;
	cin >> n >> t;

	vector<int> books(n);
	for (int i = 0; i < n; i++) cin >> books[i];

	int l = 0, r = 0;
	int sum = 0, maxBooks = 0;
	while (l < n && r < n) {
		while (r < n) {
			if (sum + books[r] <= t) {
				sum += books[r];
				r++;
			} else {
				break;
			}
		}
		maxBooks = max(maxBooks, r - l);
		sum -= books[l];
		l++;
	}

	cout << maxBooks;
	return 0;
}
