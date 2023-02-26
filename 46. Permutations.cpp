class Solution {
public:
    vector<vector<int>> ans;
    void solve (vector<int>& nums, string s, vector<int> v) {
        if (s.size() == nums.size()) {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            char c = i + '0';
            if (s.find(c) == string::npos) {
                vector<int> copy = v;
                copy.push_back(nums[i]);
                solve (nums, s + c, copy);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        solve(nums, "", v);
        return ans;
    }
};
