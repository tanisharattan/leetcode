class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
      int el1=INT_MIN;
      int el2=INT_MIN;
      int count1=0;
      int count2=0;

      for(int i=0;i<n;i++){
        if (count1==0 && nums[i]!=el2){
        count1=1;
        el1=nums[i];
        }
        else if(count2==0 && nums[i]!=el1){
             count2=1;
        el2=nums[i];
        }
        else if(nums[i]==el1){
            count1++;
        }
        else if(nums[i]==el2){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
      }
   int count3=0;
   int count4=0;
   vector<int>result;
  for(int i=0;i<n;i++){
    if(el1==nums[i])count3++;
     if(el2==nums[i])count4++;
  }
  if(count3>n/3){
     result.push_back(el1);
  }
  if(count4>n/3){
    result.push_back(el2);
  }
  return result;
    }
};