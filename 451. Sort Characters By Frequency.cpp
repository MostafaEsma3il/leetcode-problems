class Solution {
public:
    string frequencySort(string s) {
        string x = "";
        map<char, int> mp1;
        for (auto i: s) {
            mp1[i]++;
        }
        vector<pair<int,char>> v;
        for (auto i: mp1) {
            v.push_back(make_pair(i.second, i.first));
        }
        sort(v.begin(), v.end());
        for (auto i: v) {
            while (i.first--) 
                x += i.second; 
        }
        reverse(x.begin(), x.end());
        return x;
    }
};
