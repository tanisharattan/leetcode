class Solution {
public:
    string makeFancyString(string s) {
       
        string ans = "";
        int cnt = 1;
        char temp = s[0];
        ans += s[0];
        for (int i = 1; s[i] != '\0'; i++) {
            if (temp == s[i]) {
                cnt++;
            }
            else {
                temp = s[i];
                cnt = 1;
            }
            if (cnt < 3) {
                ans += s[i];
            }
        }
        return ans;
    }
};