class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        while(l <= r)
        {
            int mid = l + (r - l) / 2;

            int parts = find_k(nums, mid);

            if(parts > k)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return l;
    }

private:
    int find_k(vector<int>& nums, int limit)
    {
        int count = 1;
        int sum = 0;

        for(int x : nums)
        {
            if(sum + x <= limit)
                sum += x;
            else
            {
                count++;
                sum = x;
            }
        }

        return count;
    }
};