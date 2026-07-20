class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1;

        int max_area=0;
        while(l<r)
        {
            int area=(r-l)*min(heights[l],heights[r]);
            max_area=max(max_area,area);
            if(heights[l]<heights[r])
            {
                int temp=heights[l++];
                while(l<r&&heights[l]<=temp)
                l++;
            }
            else if(heights[l]>=heights[r])
            {
                int temp=heights[r--];
                while(l<r&&heights[r]<=temp)
                r--;
            }
        }
        return max_area;

    }
};
