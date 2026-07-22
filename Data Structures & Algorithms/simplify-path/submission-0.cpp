class Solution {
private:
    stack <string> st;
public:
    string simplifyPath(string path) {

        for(int i=1;i<path.length();i++)
        {
            while(i<path.length()&&path[i]=='/')
            i++;
            
            string s="";

            while(i<path.length()&&path[i]!='/')
            {
                s+=path[i];
                i++;
            }

            if(s=="..")
            {
                if(!st.empty())
                st.pop();
            }
            else if(s!="."&&s!="")
            st.push(s);
        }
        string s2="";
        if(st.empty())
        s2+="/";
        while(!st.empty())
        {
            s2="/"+st.top()+s2;
            st.pop();
        }
        return s2;
    }
};