class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;          // ✅ handle small arrays

        int i = 2;                     // next write position
        for (int j = 2; j < n; ++j) {
            if (nums[j] != nums[i - 2]) { // keep at most 2 of each value
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
};
