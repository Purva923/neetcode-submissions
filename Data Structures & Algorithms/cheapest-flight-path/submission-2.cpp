class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <int> min_distance(n,INT_MAX);
        vector<vector<pair<int,int>>> graph(n);

        min_distance[src]=0;

        for(int i=0;i<flights.size();i++)
        {
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        queue <tuple<int,int,int>> q;
        q.push({0,0,src});
        
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();

            auto [steps,cost,node]=temp;

            if(steps>k)
            continue;

            for(const auto &neighbour:graph[node])
            {
                int node2=neighbour.first;
                int cost2=cost+neighbour.second;
                int steps2=steps+1;

                if(cost2<min_distance[node2])
                {
                    min_distance[node2]=cost2;
                    q.push({steps2,cost2,node2});
                }
            }
        }
        return min_distance[dst]==INT_MAX?-1:min_distance[dst];
    }
};
