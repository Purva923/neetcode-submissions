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
    int final_max_sum=-1001;
    int max_sum(TreeNode * curr)
    {
        if(!curr)
        return 0;

        int max_left=max_sum(curr->left);
        int max_right=max_sum(curr->right);

        if(max_left>=0&&max_right>=0)
        {
            final_max_sum=max(final_max_sum,curr->val+max_left+max_right);
            return curr->val+max(max_left,max_right);
        }
        else if(max_left>=0)
        {
            final_max_sum=max(final_max_sum,curr->val+max_left);
            return curr->val+max_left;
        }
        else if(max_right>=0)
        {
            final_max_sum=max(final_max_sum,curr->val+max_right);
            return curr->val+max_right;
        }
        else
        {
            final_max_sum=max(final_max_sum,curr->val);
            return curr->val;
        }
    }
public:
    int maxPathSum(TreeNode* root) {
        int max_ele=max_sum(root);
        return max(max_ele,final_max_sum);
    }
};
