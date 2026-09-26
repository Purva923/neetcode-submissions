class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> subset;
        vector<vector<bool>> visited(n,vector<bool>(n,false));

        for(int i=0;i<n;i++)
        {
            string s;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                s+='Q';
                else
                s+='.';
            }
            subset.push_back(s);
            dfs(n,visited,result,subset,0,i);
            subset.pop_back();
        }

        return result;
    }
private:
    void mark_visited(vector<vector<bool>>& visited,int i1,int j1,int& n)
    {
        for(int i=0;i<n;i++)
        {
            visited[i1][i]=true;
        }

        for(int i=0;i<n;i++)
        {
            visited[i][j1]=true;
        }

        int i=i1+1,j=j1+1;
        while(i<n && j<n)
        {
            visited[i][j]=true;
            i++,j++;
        }

        i=i1-1,j=j1-1;
        while(i>=0 && j>=0)
        {
            visited[i][j]=true;
            i--,j--;
        }

        i=i1-1,j=j1+1;
        while(i>=0 && j<n)
        {
            visited[i][j]=true;
            i--,j++;
        }

        i=i1+1,j=j1-1;
        while(i<n && j>=0)
        {
            visited[i][j]=true;
            i++,j--;
        }
    }

    void dfs(int& n,vector<vector<bool>> visited,vector<vector<string>> &result,vector<string> &subset,int i1,int j1)
    {
        if(i1==n-1)
        {
            result.push_back(subset);
            return;
        }
        mark_visited(visited,i1,j1,n);

        for(int i=0;i<n;i++)
        {
            if(visited[i1+1][i])
            continue;

            string s;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                s+='Q';
                else
                s+='.';
            }
            subset.push_back(s);
            dfs(n,visited,result,subset,i1+1,i);
            subset.pop_back();
        }
    }
};
