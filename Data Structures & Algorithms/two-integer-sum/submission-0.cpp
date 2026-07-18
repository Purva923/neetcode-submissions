class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,int> m;
        vector <int> v(2);
        int n=nums.size();

        for(int i=0;i<nums.size();i++)
        m[nums[i]]++;

        for(int i=0;i<n;i++)
        {
            m[nums[i]]--;
            if(m[target-nums[i]]>0)
            {
                v[0]=i;
                for(int j=i+1;j<n;j++)
                {
                    if(nums[j]==target-nums[i])
                    {
                        v[1]=j;
                        break;
                    }
                }
                break;
            }
            m[nums[i]]++;
        }
        return v;
    }
};
