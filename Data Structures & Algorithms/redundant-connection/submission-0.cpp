class Solution {
private:
    void unite(int u,int v,vector <int>& parent)
    {
        int set_u=find_parent(u,parent);
        int set_v=find_parent(v,parent);

        parent[set_v]=set_u;
    }

    int find_parent(int u,vector <int>& parent)
    {
        if(parent[u]==u)
        return u;
        else
        return parent[u]=find_parent(parent[u],parent);
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        vector <int> parent(n+1);

        for(int i=1;i<n+1;i++)
        {
            parent[i]=i;
        }

        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            if(find_parent(u,parent)!=find_parent(v,parent))
            unite(u,v,parent);
            else
            return {u,v};
        }
    }
};
