class Solution {
public:
    map<char, vector<char>> mp;
    vector<string> ans;
    void cnt (int i, string s, string f) {
        if (i == s.size()){
            if (f.size()){
                ans.push_back(f);
            }
            return;
        }
        for (char c: mp[s[i]])
            cnt(i+1, s, f + c);
    }
    vector<string> letterCombinations(string digits) {
        char x = 'a';
        for (int i = 2; i <= 9; i++){
            char y = x;
            for (; x <= y + 2; x++)
                mp[i + '0'].push_back(x);
            if (i == 7)
                mp[i + '0'].push_back(x), x++;
        }
        mp['9'].push_back('z');
        cnt(0, digits, ""); 
        return ans;
    }
};
