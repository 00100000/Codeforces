#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> color;
vector<bool> visited;
vector<vector<int>> adj;

vector<map<int, int>> m;
vector<int> maxFreq;
vector<long long> sum;
void dfs(int node) {
	if (visited[node]) return;
	visited[node] = true;

	m[node][color[node]] = 1;
	maxFreq[node] = 1;
	sum[node] = color[node];
	for (int i = 0; i < adj[node].size(); i++) {
		if (visited[adj[node][i]]) continue;
		dfs(adj[node][i]);

		map<int, int>& cMap = m[adj[node][i]];
		long long cSum = sum[adj[node][i]];
		int cmaxFreq = maxFreq[adj[node][i]];
		// set node to the larger map
		if (cMap.size() > m[node].size()) {
			swap(cMap, m[node]);
			swap(cmaxFreq, maxFreq[node]);
			swap(cSum, sum[node]);
		}
		// update frequencies and sums
		for (auto j : cMap) {
			m[node][j.first] += cMap[j.first];
			if (m[node][j.first] > maxFreq[node]) {
				maxFreq[node] = m[node][j.first];
				sum[node] = 0;
			}
			if (m[node][j.first] == maxFreq[node]) sum[node] += j.first;
		}
		// prevent MLE
		cMap.clear();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	color.resize(n);
	adj.resize(n);
	visited.resize(n);
	m.resize(n);
	maxFreq.resize(n);
	sum.resize(n);

	for (int i = 0; i < n; i++) cin >> color[i];
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);

	for (int j = 0; j < n; j++) cout << sum[j] << " ";
	return 0;
}
