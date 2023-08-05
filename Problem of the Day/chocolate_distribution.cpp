/*
Chocolate Distribution Problem

https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
*/

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        sort(a.begin(), a.end());
        
        int i = 0, j = m-1;
        
        long long result = INT_MAX;
        
        while(j < n){
            result = min(result, (a[j]-a[i]));
            i++;
            j++;
        }
        
        return result;
    
    }   
};
