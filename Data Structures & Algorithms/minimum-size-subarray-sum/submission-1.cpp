class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector <int> v(nums.size()+1);

        v[0]=0;
        for(int i=1;i<=nums.size();i++)
        {
            v[i]=v[i-1]+nums[i-1];
        }

        int l=0,r=1;

        int count=INT_MAX;

        while(r<v.size())
        {
            if(v[r]-v[l]<target)
            r++;
            else
            {
                count=min(count,r-l);
                l++;
            }
        }
        if(count==INT_MAX)
        return 0;
        else
        return count;
    }
};