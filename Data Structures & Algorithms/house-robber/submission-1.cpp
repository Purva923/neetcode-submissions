class Solution {
private:
    pair<int,int> return_max(vector<int>&nums,int curr)
    {
        if(curr>=nums.size())
        return{0,0};
        auto next=return_max(nums,curr+1);
        int with_curr=next.second+nums[curr];
        int without_curr=max(next.first,next.second);
        return {with_curr,without_curr};
    }
public:
    int rob(vector<int>& nums) {
        auto max_ele=return_max(nums,0);
        return max(max_ele.first,max_ele.second);
    }
};
