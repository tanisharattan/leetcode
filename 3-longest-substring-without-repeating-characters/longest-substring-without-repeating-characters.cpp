class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;
        int left = 0;
        vector<int> hash(256, -1); 

        for (int right = 0; right < n; right++) {
            if (hash[s[right]] != -1 && hash[s[right]] >= left) {
                left = hash[s[right]] + 1;
            }

            hash[s[right]] = right;
            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};
