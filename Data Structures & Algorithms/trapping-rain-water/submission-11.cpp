class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;

        while(l<r&&height[l+1]>=height[l])
        l++;
        while(l<r&&height[r-1]>=height[r])
        r--;

        int sum=0;
        int h;
        while(l<r)
        {
            while(l<r&&height[l]<=height[r])
            {
                h=height[l];
                l++;
                while(l<r&&height[l]<h)
                {
                    sum+=h-height[l];
                    l++;
                }
            }
            while(l<r&&height[l]>height[r])
            {
                h=height[r];
                r--;
                while(l<r&&h>height[r])
                {
                    sum+=h-height[r];
                    r--;
                }
            }
        }
        return sum;
    }
};
