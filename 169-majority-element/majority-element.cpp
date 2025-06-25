class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n=nums.size();
     int el;
     int count=0;
     for(int i=0;i<n;i++){
        if(count==0){
            count=1;
            el=nums[i];
        }
        else if(nums[i]==el){
            count++;
        }
        else{
            count--;
        }
        
     }
     int count2=0;
     for(int i=0;i<n;i++){
        if(nums[i]==el){
            count2++;

        }}
 if(count2>n/2){
    return el;
 }
 return -1;
    }
};