class Solution {
public:
bool isValid(int r , int c , int n , int expVal ,vector<vector<int>>& grid ){
    if(r<0 || c<0 || r>=n || c>=n||grid[r][c]!=expVal){
        return false;
    }
    if(expVal==n*n-1){
        return true;
    }

    int ans1 = isValid(r-2 , c+1 , n ,expVal+1, grid);
     int ans2 = isValid(r+2 , c+1 , n ,expVal+1, grid);
      int ans3 = isValid(r-2 , c-1 , n ,expVal+1, grid);
       int ans4 = isValid(r+2 , c-1 , n ,expVal+1, grid); 
       int ans5 = isValid(r-1 , c+2 , n ,expVal+1, grid);
        int ans6 = isValid(r+1 , c+2 , n ,expVal+1, grid);
         int ans7 = isValid(r-1 , c-2 , n ,expVal+1, grid);
          int ans8 = isValid(r+1 , c-2 , n ,expVal+1, grid);

          return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
}
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid( 0 , 0 , grid.size(), 0 ,grid);
    }
};