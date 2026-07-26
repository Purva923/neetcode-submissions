class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_freq=0;
        int max_len=0;
        unordered_map<char,int> mp;

        int l=0;
        for(int r=0;r<s.length();r++)
        {
            mp[s[r]]++;
            max_freq=max(max_freq,mp[s[r]]);

            if(r-l+1-max_freq>k)
            {
                mp[s[l]]--;
                l++;
            }
            max_len=max(max_len,r-l+1);
        }
        return max_len;
    }
};
