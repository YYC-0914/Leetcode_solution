class Solution {
public:
    void bfs(vector<vector<char>> &grid, int i, int j){
        int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        while (q.size()){
            auto ver = q.front();
            q.pop();
            int x = ver.first, y = ver.second;
            // cout << x << " " << y << endl;
            for (int k = 0; k < 4; k ++){
                int a = x + dx[k], b = y + dy[k];
                if (a < 0 || a >= grid.size() || b < 0 || b >= grid[0].size()) continue;
                if (grid[a][b] == '0') continue;
                q.push({a,b});
                grid[a][b] = '0';
            }
        }
        return ;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // flood fill algorithm
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> st(n+1, vector<bool>(m+1, false));
        int res = 0;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++){
                if (grid[i][j] == '1'){
                    // cout << i << " " << j << endl;
                    bfs(grid, i, j);
                    res ++;
                }
            }
        return res;
    }
};
