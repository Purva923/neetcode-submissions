class Solution {
private:
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        int count=1;
        stack<pair<int,int>> st;
        st.push({i,j});
        grid[i][j]=0;
        vector<pair<int,int>> mv={{0,-1},{-1,0},{0,1},{1,0}};
        int n=grid.size();
        int m=grid[0].size();

        while(!st.empty())
        {
            i=st.top().first;
            j=st.top().second;
            st.pop();
            for(int i1=0;i1<4;i1++)
            {
                if(i+mv[i1].first<n&&i+mv[i1].first>=0&&j+mv[i1].second<m&&j+mv[i1].second>=0)
                {
                    if(grid[i+mv[i1].first][j+mv[i1].second]==1)
                    {
                        count++;
                        st.push({i+mv[i1].first,j+mv[i1].second});
                        grid[i+mv[i1].first][j+mv[i1].second]=0;
                    }
                }
            }
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    count=max(count,dfs(grid,i,j));
                }
            }
        }
        return count;
    }
};
