class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,set<char>> graph;
        int n=words.size();
        unordered_map<char,int> in_degree;
        string result="";

        for(auto word : words)
        {
            for(char ch : word)
                in_degree[ch] = 0;
        }

        for(int i=0;i<n-1;i++)
        {
            int notfound=1;
            for(int k=0;k<min(words[i].size(),words[i+1].size());k++)
            {
                if(words[i][k]!=words[i+1][k])
                {
                    notfound=0;
                    if(!graph[words[i][k]].count(words[i+1][k]))
                    {
                        in_degree[words[i+1][k]]++;
                        graph[words[i][k]].insert(words[i+1][k]);
                    }
                    break;
                }
            }
            if(notfound)
            {
                if(words[i].size()>words[i+1].size())
                return "";
            }
        }

        queue <char> q1;

        for(auto pr:in_degree)
        {
            if(pr.second==0)
            {
                q1.push(pr.first);
            }
        }

        while(!q1.empty())
        {
            char temp=q1.front();
            q1.pop();
            result.push_back(temp);

            for(auto temp2:graph[temp])
            {
                in_degree[temp2]--;
                if(in_degree[temp2]==0)
                {
                    q1.push(temp2);
                }
            }
        }

        if(in_degree.size()==result.size())
        return result;
        else 
        return "";
    }
};
