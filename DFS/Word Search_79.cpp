class Solution {
public:
    bool dfs(vector<vector<char>> &board, string str, vector<vector<bool>> &st, int i, int j, int idx){
        // cout << i << " " << j << endl;
        if (board[i][j] != str[idx]) return false;
        else if (idx == str.size() - 1) return true;
            // if (idx == str.size() - 1) return true;
        int n = board.size(), m = board[0].size();
        st[i][j] = true;
        int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
        for (int k = 0; k < 4; k ++){
            int a = i + dx[k], b = j + dy[k];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (st[a][b]) continue;
            if (dfs(board, str, st, a, b, idx + 1)) return true;
            }
            st[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // brute force algorithm
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> st(n+1, vector<bool>(m+1, false));
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++){
                if (board[i][j] == word[0]){
                    if (dfs(board, word, st, i, j, 0))
                        return true;
                }

            }
        return false;
        
    }
