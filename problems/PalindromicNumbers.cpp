#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// does a - b on a char array and string and prints the result
void subtract(vector<char> a, string b) {
	int carry = 0;
	// j will always be smaller than i
	for (int i = a.size() - 1, j = b.length() - 1; j >= 0; i--, j--) {
		int res = a[i] - b.at(j) + carry;
		carry = 0;
		if (res < 0) {
			carry = -1;
			res += 10;
		}
		a[i] = '0' + res;
	}
	// the numbers being subtracted are palindromes, so I kind of get
	// why this works but at the same time not really lol
	for (int i = 1; i < a.size(); i++) {
		cout << a[i];
	}
}

void solve(int digits, string num) {
	// 2 cases:
	// 10^digits + 1 - num has the same digits as num (i.e. num <= 9 * 10^(digits - 1) + 1)
	// num > 9 * 10^(digits - 1) + 1
	// we can just simplify this to checking if it starts with 9
	if (num.at(0) != '9') {
		// 100... 001 - num
		vector<char> x(digits + 1);
		x[0] = '1';
		x[digits] = '1';
		for (int i = 1; i < digits; i++) {
			x[i] = '0';
		}
		subtract(x, num);
	} else {
		// 11111... - num
		vector<char> x(digits + 1);
		for (int i = 0; i < digits + 1; i++) {
			x[i] = '1';
		}
		subtract(x, num);
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int digits;
		string num;
		cin >> digits >> num;
		solve(digits, num);
	}

	return 0;
}
