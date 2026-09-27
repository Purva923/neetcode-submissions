class Solution {
public:
    unordered_map<string,bool> mp;

    vector<string> wordBreak(string s, vector<string>& wordDic) {
        for(int i=0;i<wordDic.size();i++)
        {
            mp[wordDic[i]]=true;
        }
        vector<string> result;
        string subset;
        string word;
        dfs(s,0,subset,result,word);

        return result;
    }

private:
    void dfs(string& s,int curr,string& subset,vector<string>& result,string word)
    {
        word+=s[curr];

        if(mp.find(word)!=mp.end())
        {
            if(subset.size()!=0)
            subset+=" ";
            subset+=word;

            if(curr==s.size()-1)
            {
                result.push_back(subset);

                subset.resize(subset.size()-word.size());
                if(subset.size()!=0)
                subset.resize(subset.size()-1);

                return;
            }

            dfs(s,curr+1,subset,result,"");
            subset.resize(subset.size()-word.size());
            if(subset.size()!=0)
            subset.resize(subset.size()-1);
        }

        if(curr==s.size()-1)
        return;

        dfs(s,curr+1,subset,result,word);
    }
};