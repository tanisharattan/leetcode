class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
    vector<int>pref(n,1);
    vector<int>suf(n,1);
    vector<int>ans(n,1);
    for(int i =1;i<n;i++){
        pref[i]=pref[i-1]*nums[i-1];
    }
    for(int i =n-2 ;i>=0;i--){
            suf[i]=suf[i+1]*nums[i+1];
    }
    for(int i =0;i<n;i++){
        ans[i]=pref[i]*suf[i];
    }
    return ans;
    }
};