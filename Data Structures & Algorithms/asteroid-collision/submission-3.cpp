class Solution {
    private :
    stack <int> s1;
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector <int> v;
        for(int i=0;i<ast.size();i++)
        {
            if(s1.empty())
            s1.push(ast[i]);
            else
            {
                if(ast[i]<0)
                {
                    while(!s1.empty()&&s1.top()>0&&s1.top()<abs(ast[i]))
                    s1.pop();
                    if(s1.empty())
                    s1.push(ast[i]);
                    else if(s1.top()==abs(ast[i]))
                    s1.pop();
                    else if(s1.top()<0)
                    s1.push(ast[i]);
                }
                else
                s1.push(ast[i]);
            }
        }
        while(!s1.empty())
        {
            v.push_back(s1.top());
            s1.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};