class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r = mat.size();        // number of rows
        int c = mat[0].size();     // number of columns
        vector<int> result(r * c); // final result
        bool goUp = true;          // direction flag
        int idx = 0;               // index in result

        // loop through all diagonals
        for (int d = 0; d < r + c - 1; d++) {
            if (goUp) {
                // Start at bottom of this diagonal
                int i = (d < r) ? d : r - 1;
                int j = d - i;
                // Move NE (up-right): i--, j++
                while (i >= 0 && j < c) {
                    result[idx++] = mat[i][j];
                    i--;
                    j++;
                }
            } else {
                // Start at right of this diagonal
                int j = (d < c) ? d : c - 1;
                int i = d - j;
                // Move SW (down-left): i++, j--
                while (i < r && j >= 0) {
                    result[idx++] = mat[i][j];
                    i++;
                    j--;
                }
            }
            goUp = !goUp; // flip direction
        }

        return result;
    }
};