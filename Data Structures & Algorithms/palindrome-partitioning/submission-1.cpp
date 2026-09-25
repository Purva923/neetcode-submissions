class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> subset;
        vector<vector<string>> result;
        
        for(int i=0;i<s.length();i++)
        {
            if(is_palindrome(s,0,i))
            {
                subset.push_back(s.substr(0,i+1));
                palindrome_dfs(s,i+1,result,subset);
                subset.pop_back();
            }
        }

        return result;
    }
    
private:
    bool is_palindrome(string &s,int i1,int j1)
    {
        while(i1<=j1)
        {
            if(s[i1]!=s[j1])
            return false;

            i1++;
            j1--;
        }
        return true;
    }

    void palindrome_dfs(string &s,int i1,vector<vector<string>>& result,vector<string> &subset)
    {
        if(i1==s.size())
        {
            result.push_back(subset);
            return;
        }
        for(int i=i1;i<s.length();i++)
        {
            if(is_palindrome(s,i1,i))
            {
                subset.push_back(s.substr(i1,i-i1+1));
                palindrome_dfs(s,i+1,result,subset);
                subset.pop_back();
            }
        }
    }
};
