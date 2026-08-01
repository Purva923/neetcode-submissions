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
    int depth(TreeNode* start)
    {
        if(!start)
        return 0;

        int l=depth(start->left);
        int r=depth(start->right);

        return max(l+1,r+1);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        stack <TreeNode*> st;
        TreeNode* temp=root;
        int d=0;

        while(temp||!st.empty())
        {
            while(temp)
            {
                st.push(temp);
                temp=temp->left;
            }
            temp=st.top();
            st.pop();

            int d1,d2;
            d1=depth(temp->left);
            d2=depth(temp->right);
            d=max(d1+d2,d);

            temp=temp->right;
        }
        return d;
    }
};
