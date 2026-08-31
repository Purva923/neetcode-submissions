class Solution {
private:
    int find(int u,vector <int> & parent)
    {
        if(parent[u]==u)
        return u;
        else 
        return parent[u]=find(parent[u],parent);
    }

    void unite(int set_u,int set_v,vector <int>& parent)
    {
        parent[set_v]=set_u;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<int,vector<string>> mp1;
        unordered_map<string,vector<int>> mp2;
        unordered_map<int,vector<string>> mp3;
        vector <int> parent(accounts.size());

        for(int i=0;i<accounts.size();i++)
        {
            parent[i]=i;
        }

        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                mp1[i].push_back(accounts[i][j]);
                mp2[accounts[i][j]].push_back(i);
            }
        }


        for(auto edge:mp2)
        {
            int p1=find(edge.second[0],parent);
            for(int i=1;i<edge.second.size();i++)
            {
                int p2=find(edge.second[i],parent);
                unite(p1,p2,parent);
            }
        }

        vector <int> apex_parent;
        vector <bool> visited(accounts.size(),false);

        for(int i=0;i<accounts.size();i++)
        {
            int p1=find(i,parent);
            
            if(visited[p1])
            continue;

            visited[p1]=true;
            apex_parent.push_back(p1);
        }

        for(int i=0;i<apex_parent.size();i++)
        {
            mp3[apex_parent[i]].push_back(accounts[apex_parent[i]][0]);
        }

        for(auto pr:mp2)
        {
            int temp=find(pr.second[0],parent);
            mp3[temp].push_back(pr.first);
        }

        vector <vector<string>> result;

        for(auto pr:mp3)
        {
            result.push_back(pr.second);
        }

        return result ;
    }
};