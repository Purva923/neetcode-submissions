class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector <bool> visited(nums.size(),false);

        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }

        if(sum%k!=0)
        return false;

        int side=sum/k;

        visited[0]=true;
        sum=nums[0];
        int poss=dfs(nums,visited,sum,side,0,k);

        return poss;   
    }

private:    
    bool dfs(vector<int>& nums,vector<bool> &visited,int sum,int side,int count,int k)
    {
        if(count==k)
        return true;

        if(sum == side)
        {
            return dfs(nums, visited, 0, side, count + 1,k);
        }

        for(int i=1;i<nums.size();i++)
        {
            if(visited[i])
            continue;

            int poss=false;
            if(nums[i]!=nums[i-1]||visited[i-1])
            {
                if(sum+nums[i]>side)
                return false;

                visited[i]=true;
                poss=dfs(nums,visited,sum+nums[i],side,count,k);
                visited[i]=false;
            }

            if(poss)
            return true;
        }

        return false;
    }
};