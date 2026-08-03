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
    vector<int> rightSideView(TreeNode* root) {
        int n;
        queue <TreeNode*> q;
        q.push(root);
        vector <int> v;
        if(root==nullptr)
        return v;

        while(!q.empty())
        {
            int val;
            n=q.size();
            while(n--)
            {
                if(q.front()->left)
                q.push(q.front()->left);
                if(q.front()->right)
                q.push(q.front()->right);
                if(n==0)
                val=q.front()->val;
                q.pop();
            }
            v.push_back(val);
        }
        return v;
    }
};
