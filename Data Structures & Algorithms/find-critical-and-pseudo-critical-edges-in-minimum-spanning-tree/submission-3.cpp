class Solution {
private:
    struct Compare
    {
        bool operator()(array <int,4> &a,array <int,4> &b)
        {
            return a[2]<b[2];
        }
    };

    int find(int u,vector<int> &parent)
    {
        if(parent[u]==u)
        return u;
        else 
        return parent[u]=find(parent[u],parent);
    }

    vector <int> get_path(vector<vector<array<int,3>>> &adjList,int u,int v)
    {
        vector <int> visited(adjList.size());
        vector <pair<int,int>> parent(adjList.size());
        visited[u]=true;

        stack <int> st;
        st.push(u);
       
        while(!st.empty())
        {
            int u1=st.top();
            st.pop();

            if(u1==v)
            break;

            for(auto edge:adjList[u1])
            {
                int v1=edge[1];
                int i1=edge[2];

                if(!visited[v1])
                {
                    visited[v1]=true;
                    st.push(v1);
                    parent[v1]={u1,i1};
                }
            }
        }

        if(visited[v]==false)
        return {};

        vector <int> path;

        while(v!=u)
        {
            path.push_back(parent[v].second);
            v=parent[v].first;
        }
        reverse(path.begin(),path.end());
        return path;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector <int> parent(n);
        vector <array<int,4>> edgeList;
        vector <vector<array<int,3>>> adjList(n);
        vector <int> in_mst;
        vector <int> not_in_mst;
        vector <int> pseudo_critical;
        vector <int> critical;

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        for(int i=0;i<edges.size();i++)
        {
            edgeList.push_back({edges[i][0],edges[i][1],edges[i][2],i});
        }

        sort(edgeList.begin(),edgeList.end(),Compare());

        for(int i=0;i<edgeList.size();i++)
        {
            auto [u,v,w,i1]=edgeList[i];

            int set_u=find(u,parent);
            int set_v=find(v,parent);

            if(set_u!=set_v)
            {
                parent[set_v]=set_u;
                in_mst.push_back(i1);
                adjList[u].push_back({w,v,i1});
                adjList[v].push_back({w,u,i1});
            }
            else
            {
                not_in_mst.push_back(i1);
            }
        }

        vector <bool> pseudo(edges.size(),false);
        for(auto i:not_in_mst)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            vector <int> path=get_path(adjList,u,v);

            int flag=0;
            for(auto i1:path)
            {
                if(edges[i1][2]==w)
                {
                    flag=1;
                    pseudo[i1]=true;
                }
            }
            if(flag)
            pseudo[i]=true;
        }

        for(int i=0;i<edges.size();i++)
        {
            if(pseudo[i])
            pseudo_critical.push_back(i);
        }

        for(auto i:in_mst)
        {
            if(!pseudo[i])
            critical.push_back(i);
        }

        vector<vector<int>> result;
        result.push_back(critical);
        result.push_back(pseudo_critical);

        return result;
    }
};