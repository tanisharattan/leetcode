class Solution {
    public:
    set<vector<int>>st;
    void helper( vector<int>&comb,   int target , vector<int>&candidates , int i){
      if (target == 0) {
            st.insert(comb);  
            return;
        }
        if (target < 0 || i == candidates.size()) return;

        comb.push_back(candidates[i]);
  helper(comb , target-candidates[i],candidates, i+1);
 helper(comb , target -candidates[i],candidates, i);
 comb.pop_back();
  helper(comb ,  target , candidates, i+1 );


    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<int>comb;
      vector<vector<int>>ans;
      helper(comb , target , candidates, 0);
    return vector<vector<int>>(st.begin(), st.end());
    }
};