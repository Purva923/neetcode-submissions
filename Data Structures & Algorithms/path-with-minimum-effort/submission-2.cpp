class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> in_queue(n,vector<bool>(m,false));
        vector<vector<int>> min_distance(n,vector<int>(m,INT_MAX));
        vector<pair<int,int>> mv={{0,1},{1,0},{0,-1},{-1,0}}; 

        queue<pair<int,int>> q1;
        q1.push({0,0});
        in_queue[0][0]=true;
        min_distance[0][0]=0;

        while(!q1.empty())
        {
            pair <int,int> temp=q1.front();
            q1.pop();
            in_queue[temp.first][temp.second]=false;

            for(int i=0;i<4;i++)
            {
                pair<int,int> v;
                v.first=temp.first+mv[i].first;
                v.second=temp.second+mv[i].second;
                if(v.first<n && v.first>=0 && v.second<m && v.second>=0)
                {
                    if(min_distance[v.first][v.second]>
                    max(min_distance[temp.first][temp.second],abs(heights[v.first][v.second]-heights[temp.first][temp.second])))
                    {
                        min_distance[v.first][v.second]=max(min_distance[temp.first][temp.second],
                        abs(heights[v.first][v.second]-heights[temp.first][temp.second]));

                        if(!in_queue[v.first][v.second])
                        {
                            in_queue[v.first][v.second]=true;
                            q1.push({v.first,v.second});
                        }
                    }
                }
            }
        }
        return min_distance[n-1][m-1];
    }
};