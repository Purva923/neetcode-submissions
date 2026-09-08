class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
        vector <pair<int,int>> mv={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> min_distance(n,vector<int>(m,INT_MAX));

        pair<int,int> sr={0,0};
        min_distance[0][0] = grid[0][0];

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;

        pq.push({grid[0][0],{0,0}});

        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();

            int u=temp.second.first;
            int v=temp.second.second;

            if(visited[u][v])
            continue;

            visited[u][v]=true;

            for(int i=0;i<4;i++)
            {
                int u1=u+mv[i].first;
                int v1=v+mv[i].second;

                if(u1>=0 && u1<n && v1>=0 && v1<m)
                {
                    if(visited[u1][v1])
                    continue;

                    int new_distance = max(min_distance[u][v], grid[u1][v1]);

                    if(new_distance < min_distance[u1][v1])
                    {
                        parent[u1][v1] = {u, v};
                        min_distance[u1][v1] = new_distance;

                        pq.push({new_distance, {u1, v1}});
                    }
                }
            }
        }
        return min_distance[n-1][m-1];
    }
};
