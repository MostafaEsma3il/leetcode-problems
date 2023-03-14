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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        queue<pair<pair<int, int>, TreeNode*>> q;
        map<int,map<int,vector<int>>> mp;// we can change this map to vector.
        q.push({{0, 0}, root});

        while (!q.empty()) {
            TreeNode* n = q.front().second;
            int col = q.front().first.first;
            int row = q.front().first.second;
            q.pop();
            mp[col][row].push_back(n->val);
            if (n->left != nullptr)
                q.push({{col-1, row+1}, n->left});
            if (n->right != nullptr)
                q.push({{col+1, row+1}, n->right});
        }
        for (auto i: mp) {
            vector<int> col;
            for (auto j: i.second){
                sort(j.second.begin(), j.second.end());
                int n = j.second.size();
                for (int i = 0; i < n; i++)
                    col.push_back(j.second[i]);
            }
            ans.push_back(col);
        }
        return ans;
    }
};
