/*
Nth catalan number

https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1
*/


class Solution
{
    public:
    
    int findCatalan(int n) 
    {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 1));
        
        dp[0][0] = 1;
        
        for(int k = 1; k <= n; k++){
            for(int l = 0; l <= n; l++){
                int open = 0, close = 0;
                
                if(k > 0){
                    open = dp[k-1][l];
                }
                
                if(k < l){
                    close = dp[k][l-1];
                }
                
                dp[k][l] = (open + close) % 1000000007;
            }
        }
        
        return solve(n, n, dp);
    }

};
