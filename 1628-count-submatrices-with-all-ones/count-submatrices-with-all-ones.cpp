class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int res=0;
vector<int>height(m,0);
        for(int i =0;i<n;i++){
            for(int  j=0;j<m;j++){
               if(mat[i][j]==0) height[j]=0;
               else height[j]+=1;
            }

            for(int j =0;j<m;j++){
                int minHeight=height[j];
                for(int k =j ; k>=0 && minHeight >0 ; k--){
                  minHeight = min(minHeight , height[k]);
                    res += minHeight;
                }
            }
        }
        return res;
    }
};