/*

BFS of graph

https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

*/

void bfs(vector<int> adj[], vector<bool>& visited, vector<int>& result, int node) {
    queue<int> que;
    visited[node] = true;
    que.push(node);

    while (!que.empty()) {
        int u = que.front();
        result.push_back(u);
        que.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                que.push(v);
                visited[v] = true;
            }
        }
    }
}

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<int> result;

    for (int u = 0; u < V; u++) {
        if (!visited[u]) {
            bfs(adj, visited, result, u);
        }
    }

    return result;
}
