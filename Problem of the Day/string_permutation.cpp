/*
String Permutations

https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string-1587115620/1
*/

class Solution{
    public:
    
    void solve(string& S, string& str, vector<string>& result, int ind, int n){
        
        if(ind == n){
            result.push_back(str);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(str[i] == '$'){
                str[i] = S[ind];
                solve(S, str, result, ind+1, n);
                str[i] = '$';
            }
        }
    }
    
    vector<string> permutation(string& S)
    {
        int n = S.size();
        
        string str(n, '$');
        
        vector<string> result;
        
        solve(S, str, result, 0, n);
        
        sort(result.begin(), result.end());
        
        return result;
    }
};
