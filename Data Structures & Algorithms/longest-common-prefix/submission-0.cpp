class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s=strs[0],s2="";
        int count=strs[0].length();
        int n=strs.size();

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<count;j++)
            {
                if(strs[i][j]!=s[j])
                {
                    count=j;
                    break;
                }
            }
        }

        for(int i=0;i<count;i++)
        {
            s2+=s[i];
        }
        return s2;
    }
};