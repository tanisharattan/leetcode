class Solution {
    void helper (vector<int>& candidates,int ind , int target, vector<vector<int>>&result, vector<int>&temp ){
        if(target==0){
            result.push_back(temp);
        }

        for(int i =ind ; i<candidates.size();i++){
            if(candidates[i]>target)break;
           temp.push_back(candidates[i]);
           helper(candidates,i, target-candidates[i], result , temp);
           temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result ;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        helper(candidates,0, target, result , temp);
        return result;
    }
};