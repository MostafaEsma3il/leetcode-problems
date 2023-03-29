class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        map<int, set<string>> mp2;
        vector<string> res;
        vector<bool> cnt(505, 0);
        for (string s: words)
            mp[s]++;
        for (auto i: mp)
            mp2[i.second].insert(i.first), cnt[i.second] = 1;
        for (int i = 500; i >= 1 && k; i--)
        if (cnt[i]) {
            for (string s: mp2[i]){
                res.push_back(s), k--;
                if (!k)
                    break;
            }
        }
        return res;
    }
};
