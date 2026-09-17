class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> subset;

        if(k==0)
        return result;

        for(int curr=1;curr<=n;curr++)
        {
            subset.push_back(curr);
            dfs(n,curr+1,k,result,subset);
            subset.pop_back();
        }

        return result;
    }

private:
    void dfs(int n,int curr,int k,vector<vector<int>>&result,vector<int>&subset)
    {
        if(subset.size()==k)
        {
            result.push_back(subset);
            return ;
        }
    
        for(int i=curr;i<=n;i++)
        {
            subset.push_back(i);
            dfs(n,i+1,k,result,subset);
            subset.pop_back();
        }
    }
};