class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int XOR1=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
             XOR1=XOR1^nums[i];
        }
         return XOR1;
        
    }
};