class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        for (auto i: s)
            freq[i - 'a']++;
        vector<bool> took(26, 0);
        stack<char> stk;
    //  bcabc -> b - c - ...... a - 
        for (int i = 0; i < s.size(); i++) {
            while (!stk.empty() && stk.top() > s[i] && freq[stk.top() - 'a'] > 0 && !took[s[i] - 'a']) {
                took[stk.top() - 'a'] = 0;
                stk.pop();
            }
            if (took[s[i] - 'a']) {
                freq[s[i] - 'a'] --;
                continue;
            }
            stk.push(s[i]);
            took[s[i] - 'a'] = 1;
            freq[s[i] - 'a']--;
        }
        string ans = "";
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
