#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 2000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s;
    if (!(cin >> n >> m >> s)) return 0;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(n + 1, 0);
    priority_queue<pair<int, int>> pq;

    dist[s] = INF;
    pq.push(make_pair(INF, s));

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        
        int d = top.first;
        int u = top.second;

        if (d < dist[u]) {
            continue;
        }

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            int next_d = min(d, w);

            if (next_d > dist[v]) {
                dist[v] = next_d;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    dist[s] = -1;

    for (int i = 1; i <= n; ++i) {
        cout << dist[i];
        if (i < n) {
            cout << " ";
        }
    }
    cout << "\n";

    return 0;
}