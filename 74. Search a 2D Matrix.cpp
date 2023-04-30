class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        // Time Complexity: O(log(n) + log(m)).
        int l = 0, r = n - 1;

        while (l <= r) {
            int md = (r + l) / 2;
            if (matrix[md][0] <= target && matrix[md][m-1] >= target)
                return row(m, md, matrix, target);
            else if (matrix[md][m-1] < target)
                l = md + 1;
            else
                r = md - 1;
        }
        return 0;
    }

    bool row (int m, int i, vector<vector<int>>& matrix, int target) {
        int l = 0, r = m - 1;
        while (l <= r) {
            int md = (r + l) / 2;
            if (matrix[i][md] == target)
                return true;
            else if (matrix[i][md] < target)
                l = md + 1;
            else 
                r = md - 1;
        }
        return false;
    }
};
