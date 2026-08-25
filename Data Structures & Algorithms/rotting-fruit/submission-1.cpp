class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue <pair<int,int>> rotten;
        int n1=grid.size(),m1=grid[0].size();

        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<m1;j++)
            {
                if(grid[i][j]==2)
                rotten.push({i,j});
            }
        }


        vector <pair<int,int>> moves={{0,1},{0,-1},{1,0},{-1,0}};
        int count=0;
        int n=rotten.size();

        while(!rotten.empty())
        {
            if(n==0)
            {
                n=rotten.size();
                count++;
            }
            n--;
            auto v=rotten.front().first;
            auto h=rotten.front().second;
            rotten.pop();
            
            for(int i=0;i<4;i++)
            {
                int v1=v+moves[i].first;
                int h1=h+moves[i].second;

                if(0<=v1 && 0<=h1 && n1>v1 && m1>h1)
                {
                    if(grid[v1][h1]==1)
                    {
                        grid[v1][h1]=2;
                        rotten.push({v1,h1});
                    }
                }
            }
        }
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<m1;j++)
            {
                if(grid[i][j]==1)
                return -1;
            }
        }
        return count;
    }
};
