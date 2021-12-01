class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 以矩阵的中心点作为旋转中心，考虑每次平移之后的坐标点的变化
        // 所遵循的规律为
        // (x, y) -> (y, n-x) -> (n-x, n-y) -> (n-y, x), 这里的n为matrix.size() - 1
        // 只需要旋转 1 / 4 格即可
        int n = matrix.size() - 1;
        for (int i = 0; i <= n / 2; i ++){
            for (int j = i; j < n - i; j ++){
                // rotate matrix[i][j]
                // cout << "i " << i << " j " << j << endl;
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = matrix[j][n-i];
                matrix[j][n-i] = tmp;
            }
        }
        return ;
    }
};
