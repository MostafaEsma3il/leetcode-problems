class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string ans = "";
        while (i >= 0 || j >= 0 || carry) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int sum = x + y + carry;
            if (sum > 9) {
                carry = sum / 10;
                sum %= 10;
            }
            else {
                carry = 0;
            }
            ans += ('0' + sum);
            i--, j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
