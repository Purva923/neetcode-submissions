class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map <int,vector<int>> mp;

        for(int i=0;i<n;i++)
        {
            mp[i]={};
        }

        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }

        vector <bool> visited(n,false);
        int count=0;

        stack <pair<int,int>> st;
        st.push({0,-1});

        int vis_count=0;

        while(!st.empty())
        {
            int temp1=st.top().first;
            int parent=st.top().second;
            st.pop();

            visited[temp1]=true;
            count++;

            for(int i=0;i<mp[temp1].size();i++)
            {
                int temp2=mp[temp1][i];

                if(temp2!=parent && visited[temp2]==true)
                return false;

                else if(temp2!=parent)
                {
                    st.push({temp2,temp1});
                }
            }
        }
        return count==n;
    }
};
