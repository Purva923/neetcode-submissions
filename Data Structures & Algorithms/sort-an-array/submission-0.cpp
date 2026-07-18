class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums,0,nums.size()-1);
        return nums;
    }

    int partition(vector <int> &nums,int l,int r)
    {
        int pivot=nums[r];

        int j=l-1;
        for(int i=l;i<r;i++)
        {
            if(nums[i]<pivot)
            {
                j++;
                swap(nums[j],nums[i]);
            }
        }
        swap(nums[r],nums[j+1]);

        return j+1;
    }

    void quick_sort(vector <int> &nums,int l,int r )
    {
        if(l<r)
        {
            int m=partition(nums,l,r);
            quick_sort(nums,l,m-1);
            quick_sort(nums,m+1,r);
        }
    }
};