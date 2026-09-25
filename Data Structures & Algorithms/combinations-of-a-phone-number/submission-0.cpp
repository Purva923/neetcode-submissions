class Solution {
public:
    vector<vector<char>> list={{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

    vector<string> letterCombinations(string digits) {

        if(digits.size()==0)
        return {};

        vector<string> result;
        string subset="";

        dfs(digits,0,result,subset);

        return result;
    }

private:
    void dfs(string &digits,int curr,vector<string> &result,string &subset)
    {
        if(curr==digits.size())
        {
            result.push_back(subset);
            return;
        }
        int temp=digits[curr]-'0';

        for(int i=0;i<list[temp-2].size();i++)
        {
            subset.push_back(list[temp-2][i]);
            dfs(digits,curr+1,result,subset);
            subset.pop_back();
        }
    }
};
