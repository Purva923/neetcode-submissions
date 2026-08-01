/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int height(TreeNode * start)
    {
        if(start==nullptr)
        return 0;

        TreeNode * temp=start->left;
        int l=height(start->right);
        int r=height(start->left);

        return 1+max(l,r);
    }

public:
    bool isBalanced(TreeNode* root) {
        stack <TreeNode*> st;
        TreeNode* temp=root;
        int d1=0,d2=0;

        while(temp||!st.empty())
        {
            while(temp)
            {
                st.push(temp);
                temp=temp->left;
            }
            temp=st.top();
            st.pop();

            d1=height(temp->left);;
            d2=height(temp->right);
            if(abs(d1-d2)>1)
            return false;

            temp=temp->right;
        }
        return true;
    }
};
