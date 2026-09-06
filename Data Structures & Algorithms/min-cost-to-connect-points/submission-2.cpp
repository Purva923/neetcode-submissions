class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector <bool> visited(n,false);
        vector <int> min_dis(n,INT_MAX);
        int total_distance=0;

        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});

        int n1=n;
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();

            if(visited[temp.second])
            continue;

            total_distance+=temp.first;
            visited[temp.second]=true;
            
            for(int i=0;i<n;i++)
            {
                if(!visited[i] && min_dis[i]>
                (abs(points[i][0]-points[temp.second][0])+abs(points[i][1]-points[temp.second][1])))
                {
                    min_dis[i]=
                (abs(points[i][0]-points[temp.second][0])+abs(points[i][1]-points[temp.second][1]));
                    pq.push({min_dis[i],i});
                }
            }
        }
        return total_distance;
    }
};
