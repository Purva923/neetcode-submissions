class Solution {
public:
    vector<bool> column;
    vector<bool> pos_dia;
    vector<bool> neg_dia;
    vector<vector<string>> result;
    vector<string> subset;

    vector<vector<string>> solveNQueens(int n) {

        column.resize(n,false);
        pos_dia.resize(n*2,false);
        neg_dia.resize(n*2,false);
        subset.resize(n,string(n,'.'));

        for(int i=0;i<n;i++)
        {
            column[i]=true;
            pos_dia[i]=true;
            neg_dia[-i+n]=true;
            subset[0][i]='Q';
            dfs(n,1);
            subset[0][i]='.';
            column[i]=false;
            pos_dia[i]=false;
            neg_dia[-i+n]=false;
        }
        return result;
    }

private:
    void dfs(int &n,int i1)
    {
        if(i1==n)
        {
            result.push_back(subset);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(!column[i]&&!pos_dia[i1+i]&&!neg_dia[i1-i+n])
            {
                column[i]=true;
                pos_dia[i1+i]=true;
                neg_dia[i1-i+n]=true;
                subset[i1][i]='Q';
                dfs(n,i1+1);
                subset[i1][i]='.';
                column[i]=false;
                pos_dia[i1+i]=false;
                neg_dia[i1-i+n]=false;
            }
        }
    }
};
