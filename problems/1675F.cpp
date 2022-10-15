#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

int n, k, x, y;
vector<bool> thing;
vector<bool> vis;
vector<bool> onpathlist;
vector<vector<int>> adj;

int thingpath = -2;
bool dfs(int node) {
	if (vis[node]) return false;
	vis[node] = true;

	bool onpath = thing[node];
	for (auto i : adj[node]) {
		if (dfs(i)) onpath = true;
	}
	if (onpath) {
		thingpath += 2;
		onpathlist[node] = true;
	}
	return onpath;
}

int ypath = 1;
bool ydfs(int node) {
	if (vis[node]) return false;
	vis[node] = true;

	bool onpath = (node == y);
	for (auto i : adj[node]) {
		if (ydfs(i)) onpath = true;
	}
	if (onpath && onpathlist[node]) ypath--;
	else if (onpath && !onpathlist[node]) ypath++;
	return onpath;
}

void solve() {
	cin >> n >> k >> x >> y;
	x--;
	y--;
	thing.resize(n);
	vis.resize(n);
	onpathlist.resize(n);
	adj.resize(n);
	for (int i = 0; i < k; i++) {
		int temp;
		cin >> temp;
		temp--;
		thing[temp] = true;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(x);
	vis.clear();
	vis.resize(n);
	ydfs(x);
	cout << thingpath + ypath << "\n";
	// reset global
	thing.clear();
	vis.clear();
	onpathlist.clear();
	adj.clear();
	thingpath = -2;
	ypath = 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) solve();
	return 0;
}
