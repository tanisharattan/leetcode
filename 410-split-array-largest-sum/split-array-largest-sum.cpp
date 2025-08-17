class Solution {
    bool isValid( int maxPages, int n , int students, vector<int>&nums){
       int student=1;
       int pages=0;

       for(int i =0;i<n;i++){
        if(nums[i]>maxPages){
             return false;
        }
        else if(pages+nums[i]<=maxPages){
            pages+=nums[i];
        }
        else{
            student++;
            pages=nums[i];
        }
       }
       return student>students?false:true;
    }

    int find( vector<int>&nums , int n , int k ){
        if(k>n){
            return -1;
        }
        int sum =0;
        int ans=-1;
        for(int i =0;i<n;i++){
            sum+=nums[i];
        }
        int start=0;
        int high= sum;
      while(start<=high){
        int mid = start+(high-start)/2;
        if(isValid( mid ,n , k, nums  )){
            ans=mid;
            high=mid-1;
        }
        else{
            start=mid+1;
        }
        
      

      }
      return ans;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
      
        return   find(nums , n , k);
    }
};