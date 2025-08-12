class Solution {
private:
    void help(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& result, int ind) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
            
            if (i > ind && candidates[i] == candidates[i - 1]) continue;

           
            if (candidates[i] > target) return;

            temp.push_back(candidates[i]);
          
            help(candidates, target - candidates[i], temp, result, i + 1);
            temp.pop_back(); 
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end()); 
        help(candidates, target, temp, result, 0);
        return result;
    }
};
