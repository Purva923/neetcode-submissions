class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue <pair<int,int>> t;
        int n=grid.size();
        int m=grid[0].size();
        vector <int> d1={0,1,0,-1};
        vector <int> d2={1,0,-1,0};

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                t.push({i,j});
            }
        }

        int count=1;
        int n1=t.size();
        while(!t.empty())
        {
            if(n1==0)
            {
                count++;
                n1=t.size();
            }
            n1--;
            for(int j=0;j<4;j++)
            {
                if(0<=t.front().first+d1[j]&&0<=t.front().second+d2[j]
                &&n>t.front().first+d1[j]&&m>t.front().second+d2[j])
                {
                    if(grid[t.front().first+d1[j]][t.front().second+d2[j]]==2147483647)
                    {
                        grid[t.front().first+d1[j]][t.front().second+d2[j]]=
                        min(grid[t.front().first+d1[j]][t.front().second+d2[j]],count);

                        t.push({t.front().first+d1[j],t.front().second+d2[j]});
                    }
                }
            }
            t.pop();
        }
    }
};
