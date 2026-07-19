class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        string s="";
        int v=max(m,n);

        for(int i=0;i<v;i++)
        {
            if(i<n)
            s+=word1[i];
            if(i<m)
            s+=word2[i];
        }

        return s;
    }
};