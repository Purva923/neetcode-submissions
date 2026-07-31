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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode * temp=root;
        TreeNode * prev=nullptr;
        stack <TreeNode*> st;
        vector <int> v;

        while(temp||!st.empty())
        {
            while(temp)
            {
                st.push(temp);
                temp=temp->left;
            }

            temp=st.top();
            if(temp->right==prev||temp->right==nullptr)
            {
                prev=temp;
                v.push_back(temp->val);
                st.pop();
                temp=nullptr;
            }
            else
            temp=temp->right;
        }
        return v;
    }
};