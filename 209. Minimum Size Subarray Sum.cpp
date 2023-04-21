class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mn = 1e9;
        int l = 0, r = 0;
        int su = nums[0];
        while (l <= r && l < nums.size() && r < nums.size()) {
            if (su < target && r < nums.size() - 1)
                r++, su += nums[r];
            else {
                if (su >= target)
                    mn = min (mn, r - l + 1);
                su -= nums[l], l++;
            }
        }

        return mn == 1e9? 0: mn;
    }
};
