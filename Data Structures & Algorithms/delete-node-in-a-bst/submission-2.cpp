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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
        return root;
        else if(root->val==key)
        {
            if(root->left==nullptr&&root->right==nullptr)
            {
                delete root;
                return nullptr;
            }
            else if(root->left==nullptr)
            {
                TreeNode * temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==nullptr)
            {
                TreeNode * temp=root->left;
                delete root;
                return temp;
            }
            else 
            {
                TreeNode *temp=root,*temp2=root;
                temp=temp->left;
                while(temp->right)
                {
                    temp2=temp;
                    temp=temp->right;
                }
                root->val=temp->val;
                if(temp2->left==temp)
                temp2->left=temp->left;
                else
                temp2->right=deleteNode(temp,temp->val);
            }
        }
        else if(root->val<key)
        root->right=deleteNode(root->right,key);
        else
        root->left=deleteNode(root->left,key);

        return root;
    }
};