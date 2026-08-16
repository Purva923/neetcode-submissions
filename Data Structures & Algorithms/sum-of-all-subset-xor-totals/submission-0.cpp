class Solution {
private:
    int operation(vector <int> nums,int i,int xr)
    {
        if(i==nums.size())
        return xr;

        int l=operation(nums,i+1,xr^nums[i]);
        int r=operation(nums,i+1,xr);

        return l+r;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int total_sum=0;
        total_sum=operation(nums,0,0);
        return total_sum;
    }
};