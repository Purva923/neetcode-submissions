class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count=0;
        vector <bool> visited(n,false);
        queue <int> q;

        unordered_map<int,vector<int>> mp;

        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<n;i++)
        {
            if(visited[i])
            continue;

            q.push(i);
            count++;

            while(!q.empty())
            {
                int temp=q.front();
                q.pop();

                if(visited[temp])
                continue;

                visited[temp]=true;

                for(int i=0;i<mp[temp].size();i++)
                {
                    int temp1=mp[temp][i];
                    if(visited[temp1]==false)
                    {
                        q.push(temp1);
                    }
                }
            }
        }
        return count;
    }
};
