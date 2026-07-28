class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> d;
        vector<int> v;

        int l=0;
        for(int i=0;i<nums.size();i++)
        {
            if(d.empty())
            d.push_front(i);
            else
            {
                while(!d.empty()&&nums[d.front()]<nums[i])
                d.pop_front();
                d.push_front(i);
            }

            if(l>d.back())
            d.pop_back();

            if(i>=k-1)
            {
                v.push_back(nums[d.back()]);
                l++;
            }
        }
        return v;
    }
};
