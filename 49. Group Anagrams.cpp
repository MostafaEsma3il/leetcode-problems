class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> use;
        for (int i = 0; i < strs.size(); i++) {
            string x = strs[i];
            sort(x.begin(), x.end());
            use.push_back(make_pair(x, i));
        }
        sort(use.begin(), use.end());
        vector<vector<string>> ans;
        vector<string> push;
        push.push_back(strs[use[0].second]);
        for (int i = 1; i < use.size(); i++) {
            if (use[i].first == use[i-1].first) {
                push.push_back(strs[use[i].second]);
            }
            else {
                ans.push_back(push);
                push.clear();
                push.push_back(strs[use[i].second]);
            }
        }
        ans.push_back(push);
        push.clear();
        return ans;
    }
};
