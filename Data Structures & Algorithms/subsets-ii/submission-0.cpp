class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector <int> subset;
        result.push_back(subset);

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            if(i!=0 && nums[i-1]==nums[i])
            continue;

            subset.push_back(nums[i]);
            result.push_back(subset);
            dfs(nums,i,result,subset);
            subset.pop_back();
        }
        return result;
    }

private:
    void dfs(vector<int>& nums,int curr,vector<vector<int>> &result,vector<int> subset)
    {
        for(int i=curr+1;i<nums.size();i++)
        {
            if(i==nums.size())
            return;
            if(nums[i]==nums[i-1]&&i!=curr+1)
            continue;

            subset.push_back(nums[i]);
            result.push_back(subset);
            dfs(nums,i,result,subset);
            subset.pop_back();
        }
    }
};
