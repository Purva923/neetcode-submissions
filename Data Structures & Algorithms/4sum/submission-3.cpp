class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector <vector<int>> v;
        if (nums.size() < 4) return v;

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0&&target<nums[i])
            break;
            if(i>0&&nums[i-1]==nums[i])
            continue;

            for(int j=i+1;j<nums.size();j++)
            {
                if(j>i+1&&nums[j-1]==nums[j])
                continue;

                int l=j+1,r=nums.size()-1;
                while(l<r)
                {
                    long long sum=(long long)nums[i]+nums[j]+nums[l]+nums[r];

                    if(sum>target)
                    r--;
                    else if(sum<target)
                    l++;
                    else
                    {
                        v.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++,r--;
                        while(l<r&&nums[l-1]==nums[l])
                        l++;
                    }
                }
            }
        }
        return v;
    }
};