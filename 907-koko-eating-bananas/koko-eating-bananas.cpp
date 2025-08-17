class Solution {
public:
bool isValid(vector<int>& piles, int speed , int h ){
    int n = piles.size();
    long long hours=0;
    for(int i =0;i<n;i++){
     hours += (piles[i] + speed - 1) / speed;

    }
    if(hours>h){
        return false;
    }
    return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int high= *max_element(piles.begin(), piles.end());
        int ans=-1;

        while(low<=high){
            int mid = low+(high-low)/2;
            if(isValid(piles , mid , h)){
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};