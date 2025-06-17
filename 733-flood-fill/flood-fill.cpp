class Solution {
private:
 void dfs(vector<vector<int>>&image,vector<vector<int>>&ans,int sr,int sc,int color,int initialColor,int drow[],int dcol[]){
    ans[sr][sc]=color;
    int n =image.size();
    int m =image[0].size();

    for(int i=0;i<4;i++){
        int nrow=sr+drow[i];
        int ncol=sc+dcol[i];

        if(nrow>=0&&nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initialColor && ans[nrow][ncol]!=color){
            dfs(image,ans,nrow,ncol,color,initialColor,drow,dcol);
        }
    }

 }
public:
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initialColor=image[sr][sc];
    vector<vector<int>>&ans=image;
    int drow[]={-1,0,+1,0};
    int dcol[]={0,+1,0,-1};
    dfs(image,ans,sr,sc,color,initialColor,drow,dcol);
    return ans;
         }
};