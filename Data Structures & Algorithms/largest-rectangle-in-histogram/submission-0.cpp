class Solution {
private:
    stack <pair<int,int>> st;
public:
    int largestRectangleArea(vector<int>& heights) {
        st.push({0,heights[0]});
        int max_area=heights[0];
        int index=0;

        for(int i=1;i<heights.size();i++)
        {
            index=i;
            
            while(!st.empty()&&heights[i]< st.top().second)
            {
                max_area=max(max_area,(i-st.top().first)*st.top().second);
                index=st.top().first;
                st.pop();
            }
            st.push({index,heights[i]});
        }

        
        while(!st.empty())
        {
            max_area=max(max_area,(int)((heights.size()-st.top().first)*st.top().second));
            st.pop();
        }
        return max_area;
    }
};
