class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;

        while(l<r)
        {
            while(!isalnum(s[l]))
            l++;
            while(!isalnum(s[r]))
            r--;

            if(l<r)
            {
                if(s[l]<91&&s[l]>=65)
                s[l]+=32;
                if(s[r]<91&&s[r]>=65)
                s[r]+=32;
                if(s[l++]!=s[r--])
                return false;
            }
        }

        return true;
        
    }
};
