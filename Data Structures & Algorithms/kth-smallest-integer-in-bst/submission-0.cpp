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
public:
    int kthSmallest(TreeNode* root, int k) {
        stack <TreeNode*> st;
        TreeNode * temp=root;
        int i=0;

        while(temp||!st.empty())
        {
            while(temp)
            {
                st.push(temp);
                temp=temp->left;
            }
            temp=st.top();
            st.pop();
            i++;
            
            if(i==k)
            return temp->val;

            else temp=temp->right;
        }
    }
};
