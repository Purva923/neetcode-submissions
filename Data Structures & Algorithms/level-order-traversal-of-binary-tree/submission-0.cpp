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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector<int>> v;
        if(root==nullptr)
        return v;
        queue <TreeNode*> q;
        q.push(root);
        int n;
        v.push_back({root->val});

        while(!q.empty())
        {
            n=q.size();
            vector <int> v2;
            while(n--)
            {
                if(q.front()->left)
                {
                    v2.push_back(q.front()->left->val);
                    q.push(q.front()->left);
                }
                if(q.front()->right)
                {
                    v2.push_back(q.front()->right->val);
                    q.push(q.front()->right);
                }
                q.pop();
            }
            if(v2.size()>0)
            v.push_back(v2);
        }
        return v;
    }
};
