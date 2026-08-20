class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int max_l=0;
        unordered_map<char,int> mp;

        for(int r=0;r<s.length();r++)
        {
            if(mp.find(s[r])!=mp.end())
            {
                max_l=max(max_l,r-l);
                if(mp[s[r]]>=l)
                l=mp[s[r]]+1;
            }
            mp[s[r]]=r;
            if(r==s.length()-1)
            max_l=max(max_l,r-l+1);
        }
        return max_l;
    }
};
