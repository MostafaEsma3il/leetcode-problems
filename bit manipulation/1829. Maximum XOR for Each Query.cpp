class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        stack<int> stk;
        vector<int> ans;
        int n = nums.size();
        stk.push(nums[0]);
        for (int i = 1; i < n; i++)
            if (stk.size())
                    stk.push((stk.top()^nums[i]));
        while (stk.size()) {
            int x = stk.top();
            int p = 0;
            for (int i = 0; i < maximumBit; i++) {
                if (!(x & (1<<i))) {
                    p += (1<<i);
                }
            }
            ans.push_back(p);
            stk.pop();
        }
        return ans;
    }
};
