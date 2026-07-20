class Solution {
public:
    bool isValid(string s) {
        stack <int> stack;

        for(const char&ch : s)
        {
            if(ch=='('||ch=='{'||ch=='[')
            stack.push(ch);
            else 
            {
                if(stack.empty())
                return false;
                if(ch==')')
                {
                    if(stack.top()=='(')
                    stack.pop();
                    else 
                    return false;
                }
                else if(ch=='}')
                {
                    if(stack.top()=='{')
                    stack.pop();
                    else 
                    return false;
                }
                else if(ch==']')
                {
                    if(stack.top()=='[')
                    stack.pop();
                    else 
                    return false;
                }
            }
        }
        if(stack.empty())
        return true;
        else
        return false;
    }
};
