class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        string s1=s;

        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        for(auto &it : mp)
        {
            pq.push({it.second,it.first});
        }
        
        if(pq.top().first>((s.size()+1)/2))
        return "";

        int j=0;
        while(!pq.empty())
        {
            int a=pq.top().first;
            while(a--)
            {
                s1[j]=pq.top().second;
                if(j==s.size()-2)
                j++;
                j=(j+2)%s.size();
            }
            pq.pop(); 
        }
        return s1;
    }
};