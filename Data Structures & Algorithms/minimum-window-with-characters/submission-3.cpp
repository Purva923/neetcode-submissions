class Solution {
public:
    string minWindow(string s, string t) {
        int count=0;
        int n=s.length();
        int m=t.length();
        int l=0,r=0;
        unordered_map<int,int> mp1,mp2;

        for(int i=0;i<m;i++)
        {
            mp2[t[i]]++;
        }
        for(int i=0;i<s.length();i++)
        {
            mp1[s[i]]++;
            if(mp2.find(s[i])!=mp2.end()&&mp2[s[i]]==mp1[s[i]])
            count+=mp1[s[i]];
            if(count==m)
            {
                r=i;
                break;
            }
        }
        if(count!=m)
        return "";

        while(mp2.find(s[l])==mp2.end()||mp2[s[l]]<mp1[s[l]])
        {
            mp1[s[l]]--;
            l++;
        }
        int min_len=r-l+1;
        int min_l=l,min_r=r;
        for(int i=r+1;i<s.length();i++)
        {
            mp1[s[i]]++;
            while(mp2.find(s[l])==mp2.end()||mp2[s[l]]<mp1[s[l]])
            {
                mp1[s[l]]--;
                l++;
            }
            if(i-l+1<min_len)
            {
                min_len=i-l+1;
                min_l=l,min_r=i;
            }
        }
        return s.substr(min_l,min_r+1-min_l);
    }
};
