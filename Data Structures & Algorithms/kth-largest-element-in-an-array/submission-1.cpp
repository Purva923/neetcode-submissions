class Solution {
private:
    int partition(int l,int r,vector<int>& nums,int k)
    {
        int p=r;
        int p2=l;
        r--;
        while(l<=r)
        {
            while(l<=r&&nums[l]<=nums[p])
            l++;
            while(l<=r&&nums[r]>nums[p])
            r--;

            if(l<r)
            swap(nums[l],nums[r]);
        }
        if(l!=p)
        swap(nums[l],nums[p]);

        if(l<nums.size()-k)
        return partition(l+1,p,nums,k);
        else if(l>nums.size()-k)
        return partition(p2,l-1,nums,k);
        else
        return nums[l];
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return partition(0,nums.size()-1,nums,k);
    }
};
