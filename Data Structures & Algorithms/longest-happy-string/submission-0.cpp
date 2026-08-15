class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s="";

        priority_queue<pair<int,char>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});

        while(!pq.empty())
        {
            int n=s.size();

            if(n>=2&&pq.top().second==s[n-1]&&s[n-1]==s[n-2])
            {
                auto top_pair=pq.top();
                pq.pop();

                if(!pq.empty())
                {
                    s+=pq.top().second;
                    auto top_pair2=pq.top();
                    pq.pop();
                    top_pair2.first--;
                    if(top_pair2.first)
                    pq.push(top_pair2);
                }
                else
                return s;

                pq.push(top_pair);
            }
            else
            {
                s+=pq.top().second;
                auto top_pair2=pq.top();
                pq.pop();
                top_pair2.first--;
                if(top_pair2.first)
                pq.push(top_pair2);
            }
        }
        return s;
    }
};