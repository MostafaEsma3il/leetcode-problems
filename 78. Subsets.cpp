class Solution {
public:
    vector<vector<int>> ans;
    void all(int i, vector<int>& nums, vector<int> v) {
        if (i == nums.size()){
            ans.push_back(v);
            return;
        }
        vector<int> vtmp = v;
        vtmp.push_back(nums[i]);
        all(i+1, nums, vtmp);
        all(i+1, nums, v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        all(0, nums, {});
        return ans;
    }
};
