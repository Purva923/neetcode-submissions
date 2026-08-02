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
    bool isSameTree(TreeNode *p,TreeNode *q)
    {
        if(p==nullptr&&q==nullptr)
        return true;
        else if(p==nullptr||q==nullptr)
        return false;
        else if(p->val!=q->val)
        return false;
        else 
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode * temp=root;
        stack <TreeNode *> st;

        while(temp||!st.empty())
        {
            while(temp)
            {
                bool is_same=isSameTree(temp,subRoot);
                if(is_same)
                return true;
                st.push(temp);
                temp=temp->left;
            }

            temp=st.top();
            st.pop();
            temp=temp->right;
        }
        return false ;
    }
};
