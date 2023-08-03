/*
Shortest path in Directed Acyclic Graph

https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
*/

class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         
         vector<pair<int, int>> adj[N];
         
         for(int i = 0; i < M; i++){
             adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
         }
        
        vector<int> result(N, INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 0});
        
        result[0] = 0;
        
        while(!pq.empty()){
            int cost = pq.top().first;
            int u = pq.top().second;
            
            pq.pop();
            
            for(auto &neighbor : adj[u]){
                int v = neighbor.first;
                int dist = neighbor.second;
                
                if(result[v] > dist+cost){
                    result[v] = dist+cost;
                    
                    pq.push({result[v], v});
                }
            }
        }
        
        for(int &x : result){
            if(x == INT_MAX) x = -1;
        }
        
        return result;
    }
};
