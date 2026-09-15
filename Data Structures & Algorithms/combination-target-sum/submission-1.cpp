class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        dfs(nums,result,subset,target,0,0);

        return result;
    }

private:
    void dfs(vector <int>& nums,vector<vector<int>> &result,vector<int> subset,int target,int sum,int i1)
    {
        for(int i=i1;i<nums.size();i++)
        {
            if(sum+nums[i]>target)
            continue;

            else if(sum+nums[i]==target)
            {
                subset.push_back(nums[i]);
                result.push_back(subset);
                subset.pop_back();
            }

            else
            {
                subset.push_back(nums[i]);
                dfs(nums,result,subset,target,sum+nums[i],i);
                subset.pop_back();
            }
        }
    }
};
