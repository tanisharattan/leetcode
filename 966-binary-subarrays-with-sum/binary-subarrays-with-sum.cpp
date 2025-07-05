int f(vector<int>& nums, int goal) {
   int n=nums.size();
   if (goal < 0) return 0;
   int count=0;
   int sum=0;
   int left=0;
   for(int right =0;right<n;right++){
sum+=nums[right];

while(sum>goal){
    sum-=nums[left];
    left++;
}
count+=right-left+1;
   }
   return count;
}

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return f(nums, goal) - f(nums, goal - 1);
    }
};