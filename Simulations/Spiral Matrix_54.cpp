class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 本质上还是一个simulation
        // 共有四种不同的方向, 右下左上
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res; 
        vector<vector<bool>> st(m, vector<bool>(n,false));
        int x = 0, y = 0, cnt = 1, idx = 0;
        res.push_back(matrix[x][y]);
        st[x][y] = true;
        int k = 0;
        while(cnt <= m * n - 1 ){
            // 找到下一个满足条件的坐标
            int a = x + dx[idx], b = y + dy[idx];
            // cout << a << " " << b << endl;
            if (a >= 0 && a < m && b >= 0 && b < n && !st[a][b]){
                res.push_back(matrix[a][b]);
                cnt ++;
                st[a][b] = true;
                x = a, y = b;
            }
            else idx = (idx + 1) % 4; 
        }
        return res;
    }
};
