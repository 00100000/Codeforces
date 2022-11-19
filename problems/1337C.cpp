#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

vector<vector<int>> adj;
vector<int> dist;
vector<int> subtree;
vector<bool> vis;

void dfs(int node, int d) {
	if(vis[node]) return;
	vis[node] = true;
	dist[node] = d;
	for (auto i : adj[node]) {
		if (!vis[i]) {
			dfs(i, d + 1);
			subtree[node] += subtree[i] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	adj.resize(n);
	dist.resize(n);
	subtree.resize(n);
	vis.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0, 0);
	// industry cities must always be the parents of other industry cities
	// turning a city into a industry city removes one from the path of all
	// the industry cities on its subtree
	for (int i = 0; i < n; i++) dist[i] -= subtree[i];
	sort(dist.begin(), dist.end());

	long long sum = 0;
	for (int i = n - 1; i >= n - k; i--) sum += dist[i];

	cout << sum;
	return 0;
}
