class Solution {
public:
    bool isAnagram(string s, string t) {
        map <char,int> m1,m2;

        if(s.length()!=t.length())
        return false;

        for(int i=0;i<s.length();i++)
        m1[s[i]]++;

        for(int i=0;i<t.length();i++)
        m2[t[i]]++;

        if(m1==m2)
        return true;
        else
        return false;
    }
};
