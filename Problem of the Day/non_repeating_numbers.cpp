/*
Non Repeating Numbers

https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1
*/

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        unordered_map<int, int> umap;
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            umap[nums[i]]++;
        }
        
        vector<int> ans;
        
        for(auto it: umap){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
