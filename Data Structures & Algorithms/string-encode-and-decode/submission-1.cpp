class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";

        for(int i=0;i<strs.size();i++)
        {
            int l=strs[i].length();
            s+=("#"+to_string(l)+"#"+strs[i]);
        }
        return s;
    }

    vector<string> decode(string s) {
        vector <string> strs;

        int i=1;

        while(i<s.length())
        {
            string l1="";  
            
            while(s[i]!='#')
            {
                l1+=s[i];
                i++;
            }
            int l=stoi(l1);

            i++;
            strs.push_back(s.substr(i,l));
            i+=l+1;

        }
        return strs;
    }
};
