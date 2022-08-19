#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

int main() {
	ios::sync_with_stdio(false);

	int l = 1, r = 1000000;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		cout << mid << endl;
		string resp;
		cin >> resp;
		if (resp.compare("<") == 0) r = mid - 1;
		if (resp.compare(">=") == 0) l = mid;
	}

	cout << "! " << l << endl;
	return 0;
}
