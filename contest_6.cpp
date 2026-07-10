#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];
int target_node;
bool is_found = false;

void dfs(int u) {
    visited[u] = true;
    
    if (u == target_node) {
        is_found = true;
        return;
    }
    //перебираем соседей вершины u
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);
            
            if (is_found) return; 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v;
    if (!(cin >> n >> m >> u >> v)) return 0;
    // читаем входные данные и расставляем соседей
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    target_node = v;
    parent[u] = -1;

    dfs(u);

    if (!visited[v]) {
        cout << -1 << "\n";
    } else {
        // вектор который сохраняет вершины пути
        vector<int> path;
        int curr = v;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }

        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i + 1 < path.size()) {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}