/*
Coin Change

https://practice.geeksforgeeks.org/problems/coin-change2448/1
*/

class Solution {
  public:
  
    long long int count(int coins[], int N, int sum) {
        
        vector<vector<long long int>> dp(N, vector<long long int> (sum+1, 0));
        
        for(int i = 0; i <= sum; i++){
            if(i%coins[0] == 0) dp[0][i] = 1;
            else dp[0][i] = 0;
        }
        
        for(int i = 0; i < N; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i < N; i++){
            for(int j = 1; j <= sum; j++){
                long long int notTake = dp[i-1][j];
                
                long long int take = 0;
                
                if(coins[i] <= j){
                    take = dp[i][j-coins[i]];
                }
                
                dp[i][j] = take+notTake;
            }
        }
        

        return dp[N-1][sum];
        
    }
};
