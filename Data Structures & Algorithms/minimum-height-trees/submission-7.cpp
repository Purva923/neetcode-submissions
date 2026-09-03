class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph;
        vector<int> in_degree(n,0);

        if(n==1)
        return {0};

        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            in_degree[edges[i][0]]++;
            in_degree[edges[i][1]]++;
        }

        queue <int> q1;

        for(int i=0;i<n;i++)
        {
            if(in_degree[i]==1)
            {
                q1.push(i);
            }
        }

        int count=n;

        while(count>2)
        {
            int count1=q1.size();
            count-=count1;

            while(count1--)
            {
                int temp=q1.front();
                q1.pop();

                for(auto &edge:graph[temp])
                {
                    in_degree[edge]--;
                    if(in_degree[edge]==1)
                    {
                        q1.push(edge);
                    }
                }
            }
        }
        vector<int> result;

        while(!q1.empty())
        {
            result.push_back(q1.front());
            q1.pop();
        }

        return result;
        
    }
};