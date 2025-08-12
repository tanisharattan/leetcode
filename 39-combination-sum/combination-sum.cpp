class Solution {
    private:
    void help(vector<int>& candidates, int target , vector<int>&temp , vector<vector<int>>&result, int ind){
        if(target==0){
            result.push_back(temp);
        }
        for(int i = ind ; i <candidates.size();i++){
            if(candidates[i]>target)return ;
            temp.push_back(candidates[i]);
            help(candidates , target-candidates[i], temp , result ,i );
            temp.pop_back();
        }

    }
  
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>>result ;
       vector<int>temp ;
       sort(candidates.begin(),candidates.end());
       help(candidates , target , temp , result , 0 );
      return result ;
    }
};