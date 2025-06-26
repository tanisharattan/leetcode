class Solution 
{
public:
    int longestSubsequence(string s, int k) 
    {
        // Step 1: Count all zeros
        int zeros = count(s.begin(), s.end(), '0');

        // Step 2: Initialize variables
        long long value = 0;
        int power = 0;
        int count = 0;

        
        for (int i = s.size() - 1; i >= 0 && power < 32; --i) 
        {
            if (s[i] == '1') 
            {
                value += 1LL << power;
                if (value > k)
                {
                    break;
                }

                count++;
                power++;
            } 
            else 
            {
                power++;
            }
        }

       
        return count + zeros;
    }
};