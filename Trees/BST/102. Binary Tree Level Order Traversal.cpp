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
        vector<vector<int>> levels;
        if (!root)
            return levels;
        vector<int> l;
        queue<pair<int,TreeNode*>> q;
        q.push(make_pair(0, root));
        int lLevel = 0;
        while (!q.empty()) {
            TreeNode* curr = q.front().second;
            int nLevel = q.front().first;
            q.pop();
            if (nLevel == lLevel)
                l.push_back(curr->val);
            else {
                levels.push_back(l);
                l.clear();
                l.push_back(curr->val);
            }
            lLevel = nLevel;
            if (curr->left != NULL)
                q.push(make_pair(nLevel + 1, curr->left));
            if (curr->right != NULL)
                q.push(make_pair(nLevel + 1, curr->right));
            
        }
        levels.push_back(l);
        return levels;
    }
};
