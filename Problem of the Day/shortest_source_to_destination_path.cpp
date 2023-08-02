/*
Shortest Source to Destination Path

https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1
*/

class Solution {
  public:
  
	bool possible(int x, int y, int n, int m) {
		if (x >= 0 && y >= 0 && x < n && y < m) return true;

		return false;
	}

	int bfs(vector<vector<int>>& matrix, vector<vector<int>>& directions, int X, int Y, int n, int m) {

		queue<pair<int, int>> pq;

		int x = 0, y = 0;

		pq.push({x, y});

		matrix[x][y] = 0;

		int level = 0;

		while (!pq.empty()) {

            int size = pq.size();
            
            for(int i = 0; i < size; i++){
    			x = pq.front().first;
    			y = pq.front().second;
    
    			pq.pop();
    
    			if (x == X && y == Y) return level;
    
    			for (auto dir : directions) {
    				int x_ = x + dir[0];
    				int y_ = y + dir[1];
    
    				if (possible(x_, y_, n, m) && matrix[x_][y_] == 1) {
    					pq.push({x_, y_});
    					matrix[x_][y_] = 0;
    				}
    			}
            }

			level++;
		}

		return -1;
	}

	int shortestDistance(int N, int M, vector<vector<int>>& A, int X, int Y) {
		if (A[0][0] == 0 || N == 0 || M == 0 || X >= N || Y >= M) return -1;

		if (X == 0 && Y == 0) return 0;

		vector<vector<int>> directions = {{0, -1}, {0, 1}, { -1, 0}, {1, 0}};

		return bfs(A, directions, X, Y, N, M);
	}
};
