class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n=tickets.size();
        unordered_map<string,vector<string>> mp;
        unordered_map <string,int> out_degree;
        vector <string> result;
        
        for(int i=0;i<n;i++)
        {
            mp[tickets[i][0]].push_back(tickets[i][1]);
            out_degree[tickets[i][0]]++;
        }

        for(auto &it : mp)
        {
            sort(it.second.rbegin(), it.second.rend());
        }

        string temp="JFK";
        int count=0;

        stack <string> st;
        st.push(temp);

        while(count!=n)
        {
            while(out_degree[temp])
            {
                int c=mp[temp].size();
                string temp1=mp[temp][c-1];
                mp[temp].pop_back();
                out_degree[temp]--;
                count++;

                temp=temp1;
                st.push(temp);
            }

            if(count!=n)
            {
                while(!out_degree[st.top()])
                {
                    result.push_back(st.top());
                    st.pop();
                }
                temp=st.top();
            }
        }

        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
