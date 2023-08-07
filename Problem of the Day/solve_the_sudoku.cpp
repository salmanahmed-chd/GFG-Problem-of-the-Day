/*
Solve the Sudoku

https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
*/

class Solution 
{
    public:
    
    bool isSafe(int grid[N][N], int row, int col, int value) {
        for (int i = 0; i < N; i++) {
            if (grid[row][i] == value || grid[i][col] == value)
                return false;
        }
    
        int nrow = (row / 3) * 3;
        int ncol = (col / 3) * 3;
    
        for (int i = nrow; i < nrow + 3; i++) {
            for (int j = ncol; j < ncol + 3; j++) {
                if (grid[i][j] == value)
                    return false;
            }
        }
    
        return true;
    }

    
    bool solve(int grid[N][N]){
        
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(grid[row][col] == 0){
                    
                    for(int i = 1; i <= 9; i++){
                        
                        if(isSafe(grid, row, col, i)){
                            
                            grid[row][col] = i;
                            
                            if(solve(grid)) return true;
                            
                            grid[row][col] = 0;
                            
                        }
                    }
                    
                    return false;
                    
                }
            }
        }
        
        return true;
    }
     
    bool SolveSudoku(int grid[N][N])  
    { 
        return solve(grid);
    }
    
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};
