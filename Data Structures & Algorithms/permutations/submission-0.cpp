class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(),false);
        vector<int> subset;
        vector<vector<int>>result;

        for(int i=0;i<nums.size();i++)
        {
            visited[i]=true;
            subset.push_back(nums[i]);
            dfs(nums,visited,1,subset,result);
            subset.pop_back();
            visited[i]=false;
        }

        return result;
    }

private:
    void dfs(vector<int> &nums,vector<bool>visited,int count,vector<int> subset,vector<vector<int>> &result)
    {
        if(nums.size()==count)
        {
            result.push_back(subset);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                subset.push_back(nums[i]);
                dfs(nums,visited,count+1,subset,result);
                subset.pop_back();
                visited[i]=false;

            }
        }
    }
};
