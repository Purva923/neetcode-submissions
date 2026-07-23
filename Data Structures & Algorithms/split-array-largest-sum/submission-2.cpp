class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);

        while(l<=r)
        {
            int mid=(l+r)/2;

            int k1=find_k(nums,k,mid);

            if(k1>k)
            l=mid+1;
            else
            r=mid-1;
        }
        return l;
    }

private:
    int find_k(vector<int>& nums, int k,int mid)
    {
        int count=1;
        int i=0;
        int sum=0;
        while(i<nums.size())
        {
            if(sum+nums[i]<=mid)
            sum+=nums[i];
            else
            {
                count++;
                sum=nums[i];
            }
            i++;
        }
        return count ;
    }
};