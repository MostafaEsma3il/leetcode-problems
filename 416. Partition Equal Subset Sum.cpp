class Solution {
public:
    int memo[205][20005];
    bool can (int i, vector<int>& nums, int su, int h) {
        if (i == nums.size() || su > h)
            return 0;
        if (su == h)
            return 1;
        if (memo[i][su] != -1)
            return memo[i][su];
        return memo[i][su] = can(i+1, nums, su+nums[i], h) || can(i+1, nums, su, h);
    }
    bool canPartition(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        int tot = 0;
        map<int, int> mp;
        for (int i: nums)
            tot += i, mp[i]++;
        if (tot % 2)
            return 0;
        int half = tot / 2;
        return can(0, nums, 0, half);
    }
};
