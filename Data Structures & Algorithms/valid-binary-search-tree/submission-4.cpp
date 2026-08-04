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
private :
    bool isvalid(TreeNode * root,int min,int max)
    {
        if(root==nullptr)
        return true;

        bool b1,b2,b3;
        if(root->val<=min||root->val>=max)
        return false;
        if(!root->right&&!root->left)
        b1=true;
        else if(!root->left&&root->right->val>root->val)
        b1=true;
        else if(!root->right&&root->left->val<root->val)
        b1=true;
        else if(root->right&&root->left&&
        root->right->val>root->val&&root->left->val<root->val)
        b1=true;
        else 
        return false;

        b2=isvalid(root->left,min,root->val);
        b3=isvalid(root->right,root->val,max);

        return b1&&b2&&b3;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isvalid(root,-1001,1001);
    }
};
