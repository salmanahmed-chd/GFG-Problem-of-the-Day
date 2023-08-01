/*
DFS of Graph

https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
*/
    void dfs(vector<int> adj[], vector<int>& result, int u, vector<bool>& visited){
        visited[u] = true;
        
        result.push_back(u);
        
        for(int &v: adj[u]){
            if(!visited[v]){
                dfs(adj, result, v, visited);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<bool> visited(V, false);
        
        vector<int> result;
        
        dfs(adj, result, 0, visited);
        
        return result;
    }
