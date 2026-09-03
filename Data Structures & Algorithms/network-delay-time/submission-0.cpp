class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1); 

        for(int i=0;i<times.size();i++)
        {
            graph[times[i][0]].push_back({times[i][2],times[i][1]});
        }

        vector <bool> visited(n+1,false);
        vector <int> min_distance(n+1,INT_MAX);
        min_distance[k]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            
            if(visited[temp.second])
            continue;

            visited[temp.second]=true;

            for(auto temp1:graph[temp.second])
            {
                if(!visited[temp1.second] && 
                min_distance[temp1.second]>min_distance[temp.second]+temp1.first)
                {
                    min_distance[temp1.second]=min_distance[temp.second]+temp1.first;
                    pq.push({min_distance[temp1.second], temp1.second});
                }
            }
        }
        
        int result=*max_element(min_distance.begin()+1,min_distance.end());
        if(result==INT_MAX)
        return -1;
        else 
        return result;
    }
};
