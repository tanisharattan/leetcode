class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
         int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // (time, row, col)
        pq.push({grid[0][0], 0, 0});
        int ans = 0;
        
        // Directions: up, down, left, right
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int t = top[0];
            int r = top[1];
            int c = top[2];
            
            ans = max(ans, t);
            
            if(r == n-1 && c == n-1) return ans;  // reached destination
            
            if(visited[r][c]) continue;
            visited[r][c] = 1;
            
            for(auto& d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }
        return -1; 
    }
};