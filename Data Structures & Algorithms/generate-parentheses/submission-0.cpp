class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int ob=1,cb=0;
        vector <string> result;
        string subset;
        subset+='(';
        dfs(n,ob,cb,subset,result);
        return result;
    }

private:
    void dfs(int n,int ob,int cb,string subset,vector <string> &result)
    {
        if(cb==n)
        {
            result.push_back(subset);
            return;
        }

        if(ob<n)
        {
            dfs(n,ob+1,cb,subset+'(',result);
        }
        if(ob>cb)
        {
            dfs(n,ob,cb+1,subset+')',result);
        }
    }
};
