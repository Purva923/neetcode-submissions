class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,unordered_set<int>> graph;

        vector arr={0};
        if(n==1)
        return arr;

        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }

        vector <bool> visited(n,false);
        queue <int> q1;

        for(auto &edges:graph)
        {
            if(edges.second.size()==1)
            {
                q1.push(edges.first);
                edges.second.clear();
                visited[edges.first]=true;
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

                for(auto &edges:graph)
                {
                    edges.second.erase(temp);
                    if(edges.second.size()==1)
                    {
                        q1.push(edges.first);
                        edges.second.clear();
                        visited[edges.first]=true;
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