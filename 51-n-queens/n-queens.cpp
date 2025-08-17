class Solution {
    bool isValid(vector<string>& board, int row, int col, int n) {
  
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
      
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
       
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void nQueens(vector<string>& board, vector<vector<string>>& ans, int n, int row) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';         
                nQueens(board, ans, n, row+1);
                board[row][col] = '.';         
            }
        }
    }
   
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); 
        nQueens(board, ans, n, 0);
        return ans;
    }
};
