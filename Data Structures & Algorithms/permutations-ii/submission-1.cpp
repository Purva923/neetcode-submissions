class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector <int> subset;
        vector <bool> visited(nums.size(),false);

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            if(i!=0 && nums[i-1]==nums[i])
            continue;

            subset.push_back(nums[i]);
            visited[i]=true;
            dfs(nums,i,result,subset,visited,1);
            visited[i]=false;
            subset.pop_back();
        }
        return result;
    }

private:
    void dfs(vector<int>& nums,int curr,vector<vector<int>> &result,vector<int> subset,vector<bool> visited,int count)
    {
        if(count==nums.size())
        {
            result.push_back(subset);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i])
            continue;


            if(i!=0 && nums[i]==nums[i-1]&&!visited[i-1])
            continue;

            subset.push_back(nums[i]);
            visited[i]=true;
            dfs(nums,i,result,subset,visited,count+1);
            visited[i]=false;
            subset.pop_back();
        }
    }
};