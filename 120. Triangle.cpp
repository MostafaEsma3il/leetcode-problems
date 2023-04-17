class Solution {
public:
    int memo[205][205];
    int best (int i, int j, vector<vector<int>>& tri) {
        if (i == tri.size() || j == -1 || j == i +1)
            return 1e9;
        if (i == tri.size() - 1)
            return tri[i][j];
        if (memo[i][j] != -1)
            return memo[i][j];
        return memo[i][j] = tri[i][j] + min(best(i+1, j, tri), best(i+1, j+1, tri));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(memo, -1, sizeof(memo));
        return best(0, 0, triangle);
    }
};
