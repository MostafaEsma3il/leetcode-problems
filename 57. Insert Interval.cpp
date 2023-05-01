class Solution {
public:
    // Time: O(n) - Space: O(n)			
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        bool done = 0;
        for (int i = 0; i < n; i++) {
            if (!done) {
                if (newInterval[0] < intervals[i][0] || (newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1])) {
                    vector<int> x;
                    x.push_back(min(newInterval[0], intervals[i][0]));
                    while (i < n && newInterval[1] > intervals[i][1]) {
                        i++;
                    }
                    if (i == n)
                        x.push_back(newInterval[1]);
                    else {
                        if (newInterval[1] <= intervals[i][1])
                            if (newInterval[1] >= intervals[i][0])
                                x.push_back(intervals[i][1]);
                            else 
                                x.push_back(newInterval[1]), i--;
                    }
                    res.push_back(x);
                    done = 1;
                }
                else {
                    res.push_back(intervals[i]);
                }
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        if (!done)
            res.push_back(newInterval);
        return res;
    }
};
