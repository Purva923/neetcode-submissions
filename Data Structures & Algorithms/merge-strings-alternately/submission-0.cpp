class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        string s="";
        int small=min(m,n);

        for(int i=0;i<small;i++)
        {
            s+=word1[i];
            s+=word2[i];
        }

        int m1=m-small;
        int n1=n-small;
        if(m1)
        s+=word2.substr(small,m1);
        else
        s+=word1.substr(small,n1);

        return s;
    }
};