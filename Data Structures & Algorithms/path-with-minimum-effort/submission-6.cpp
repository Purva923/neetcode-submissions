class Solution {
private:
    vector<int> find_min(vector<vector<int>>& min_distance,vector<vector<bool>>&visited,int n,int m)
    {
        int min=INT_MAX;
        int x=-1,y=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && min>min_distance[i][j])
                {
                    min=min_distance[i][j];
                    x=i;
                    y=j;
                }
            }
        }
        return {x,y};
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector <vector<int>> min_distance(n,vector<int>(m,INT_MAX));
        vector <vector<int>> parent(n,vector<int>(m));
        vector <vector<bool>> visited(n,vector<bool>(m,false));
        vector <vector<int>> mv={{0,1},{1,0},{0,-1},{-1,0}}; 

        min_distance[0][0]=0;

        int c=n*m-1;
        while(c--)
        {
            auto u=find_min(min_distance,visited,n,m);
            if(u[0]==-1&&u[1]==-1)
            {
                continue;
            }
            visited[u[0]][u[1]]=true;

            for(int i=0;i<4;i++)
            {
                vector<int> v(2);
                v[0]=u[0]+mv[i][0];
                v[1]=u[1]+mv[i][1];
                if(u[0]+mv[i][0]<n && u[0]+mv[i][0]>=0 && u[1]+mv[i][1]<m && u[1]+mv[i][1]>=0)
                {
                    if(min_distance[v[0]][v[1]]>max(min_distance[u[0]][u[1]],abs(heights[v[0]][v[1]]-heights[u[0]][u[1]])))
                    {
                        min_distance[v[0]][v[1]]=max(min_distance[u[0]][u[1]],
                        abs(heights[v[0]][v[1]]-heights[u[0]][u[1]]));
                    }
                }
            }
        }
        return min_distance[n-1][m-1];
    }
};