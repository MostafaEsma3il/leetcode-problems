class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> final;
        final.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= final.back()[1]) {
                final.back()[1] = max(final.back()[1], intervals[i][1]);
            }
            else {
                final.push_back(intervals[i]);
            }
        }
        return final;
    }
};
