class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int pos[10005], neg[10005];
        memset(pos, 0, sizeof(pos));
        memset(neg, 0, sizeof(neg));
        for (int i: nums){
            if (i >= 0)
                pos[i]++;
            else 
                neg[(i * -1)]++; 
        }
        int c = 0;
        for (int i = 10000; i >= 0; i--)
            while (pos[i] > 0){
                c++;
                if (c == k)
                    return i;
                pos[i]--;
            }
        for (int i = 1; i <= 10000; i++)
            while (neg[i] > 0) {
                c++;
                if (c == k)
                    return i * -1;
                neg[i]--;
            }
        return 0;
    }
};
