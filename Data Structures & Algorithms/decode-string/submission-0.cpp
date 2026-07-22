class Solution {
    private:
    stack <string> st;
public:
    string decodeString(string s) {
        string s1;
        int n=s.length();

        for(int i=0;i<n;i++)
        {
            string s2="";
            if(s[i]==']')
            {
                while(st.top()!="[")
                {
                    s2=st.top()+s2;
                    st.pop();
                }
                st.pop();
                string r1="";
                while(!st.empty()&&st.top()>="0"&&st.top()<="9")
                {
                    r1=st.top()+r1;
                    st.pop();
                }
                int r=stoi(r1)-1;

                string s3=s2;
                while(r--)
                s2+=s3;

                st.push(s2);
            }
            else
            st.push(string(1,s[i]));
        }
        
        while(!st.empty())
        {
            s1=st.top()+s1;
            st.pop();
        }
        return s1;
    }
};