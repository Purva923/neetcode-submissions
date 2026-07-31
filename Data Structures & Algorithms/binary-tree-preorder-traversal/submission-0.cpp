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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode * temp=root;
        stack <TreeNode*> st;
        vector <int> v;

        while(temp||!st.empty())
        {
            while(temp)
            {
                st.push(temp);
                v.push_back(temp->val);
                temp=temp->left;
            }

            temp=st.top();
            st.pop();

            temp=temp->right;
        }
        return v;
    }
};