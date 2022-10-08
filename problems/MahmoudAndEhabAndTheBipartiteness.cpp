#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

typedef long long ll;

ll redCnt = 0;
vector<vector<ll>> adj;
vector<bool> vis;
vector<bool> color;

void dfs(ll node, ll lastColor) {
	if (vis[node]) return;
	vis[node] = true;
	color[node] = !lastColor;
	if (color[node]) redCnt++;
	for (auto i : adj[node]) dfs(i, color[node]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;
	adj.resize(n);
	vis.resize(n);
	color.resize(n);
	for (ll i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, false);
	// connect all red edges to all blue edges
	ll cnt = redCnt * (n - redCnt);
	for (ll i = 0; i < n; i++) {
		// remove existing connections
		if (color[i]) cnt -= adj[i].size();
	}

	cout << cnt;
	return 0;
}
