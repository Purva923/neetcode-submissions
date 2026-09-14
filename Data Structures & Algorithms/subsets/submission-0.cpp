class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>result;
        vector<int> subset;
        result.push_back(subset);
        dfs(0,subset,result,nums);

        return result;
    }

private:
    void dfs(int i,vector<int> subset,vector<vector<int>>& result,vector<int>&nums)
    {
        if(i==nums.size())
        return;

        dfs(i+1,subset,result,nums);

        subset.push_back(nums[i]);
        result.push_back(subset);
        dfs(i+1,subset,result,nums);

    }
};
