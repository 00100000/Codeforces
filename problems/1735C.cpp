#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

struct DSU {
	vector<int> parent;

	DSU() {
		parent.resize(26);
		for (int i = 0; i < 26; i++) parent[i] = i;
	}
	int find(int a) {
		if (parent[a] == a) return a;
		return find(parent[a]);
	}
	bool join(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return false;
		parent[b] = a;
		return true;
	}
};

void solve() {
	int n;
	string t;
	cin >> n >> t;

	vector<int> adj(26);
	vector<bool> used(26);
	DSU dsu;
	// functional graph with each node having exactly one edge that leads to it and
	// that can't be a cycle until every letter is used
	for (int i = 0; i < 26; i++) adj[i] = -1;
	for (int i = 0; i < n; i++) {
		int c = t.at(i) - 'a';
		if (adj[c] == -1) {
			for (int j = 0; j < 26; j++) {
				if (c != j && !used[j] && (j == 25 || dsu.join(c, j))) {
					used[j] = true;
					adj[c] = j;
					break;
				}
			}
		}
		cout << (char)(adj[c] + 'a');
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}
	return 0;
}
