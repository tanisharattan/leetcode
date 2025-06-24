class Solution {
public:
    int count_Set_Bits(int n) {
        int count = 0;
        while (n != 0) {
            n = (n & (n - 1)); 
            count++;
        }
        return count;
    }

    int hammingWeight(int n) {
        return count_Set_Bits(n);
    }
};