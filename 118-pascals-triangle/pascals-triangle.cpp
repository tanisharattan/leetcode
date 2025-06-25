class Solution {
    private:
     vector<int>parscal(int row){
         vector<int>anss;
        long long ans=1;
        anss.push_back(1);
        for(int col=1;col<=row;col++){
            ans=ans*(row-col+1);
            ans=ans/(col);
            anss.push_back(ans);
        }

return anss;

     }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
             ans.push_back(parscal(i));
        }
        return ans;
    }
};