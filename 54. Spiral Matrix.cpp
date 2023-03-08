class Solution {
public:
    int n, m;
    vector<int> ans;
    int vis[15][15];
    void dfs (int i, int j, vector<vector<int>>& matrix) {
        if (i == n || i < 0 || j == m || j < 0 || vis[i][j])
            return;
        while (j < m && !vis[i][j])
            vis[i][j] = 1, ans.push_back(matrix[i][j]), j++;
        j--;
        i++;
        while (i < n && !vis[i][j])
            vis[i][j] = 1, ans.push_back(matrix[i][j]), i++;
        i--;
        j--;
        while (j >= 0  && i >= 0 && i < n && j < m&& !vis[i][j])
            vis[i][j] = 1, ans.push_back(matrix[i][j]), j--;
        j++;
        i--;
        while (i >= 0 && i < n && !vis[i][j])
            vis[i][j] = 1, ans.push_back(matrix[i][j]), i--;
        i++;
        j++;
        dfs (i, j, matrix);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        memset(vis, 0, sizeof (vis));
        dfs(0, 0, matrix);
        return ans;
    }
};
