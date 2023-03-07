class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int idx = 1000;
        int l = 0;
        int r = nums.size() - 1;
        int n = nums.size();
        while (l <= r) {
            int mid = (r + l) / 2;
            double lVal = mid == 0? -1000000000000 : nums[mid-1];
            double rVal = mid == n - 1? -1000000000000 : nums[mid+1];
            if (double(nums[mid]) > lVal && double(nums[mid]) > rVal){
                idx = mid;
                break;
            }
            else if (double(nums[mid]) > lVal && double(nums[mid]) < rVal)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return idx;
    }
};
