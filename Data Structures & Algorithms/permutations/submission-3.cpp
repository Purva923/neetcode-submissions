class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset=nums;
        int count=0;
        result.push_back(nums);
        dfs(subset,result,count);

        return result;
    }

private:
    void dfs(vector<int> &subset,vector<vector<int>>&result,int count)
    {
        if(count==subset.size())
        return;
        dfs(subset,result,count+1);

        for(int i=count+1;i<subset.size();i++)
        {
            swap(subset[count],subset[i]);
            result.push_back(subset);
            dfs(subset,result,count+1);
            swap(subset[count],subset[i]);
        }
    }
};
