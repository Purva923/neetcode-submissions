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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp=root;
        TreeNode *newnode=new TreeNode(val);

        if(root==nullptr)
        return newnode;

        while(true)
        {
            if(temp->val<val)
            {
                if(temp->right==nullptr)
                {
                    temp->right=newnode;
                    break;
                }
                else 
                temp=temp->right;
            }
            else if(temp->val>val)
            {
                if(temp->left==nullptr)
                {
                    temp->left=newnode;
                    break;
                }
                else 
                temp=temp->left;
            }
        }
        return root ;
    }
};