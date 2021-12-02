class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int x = 0, y = m - 1;
        while (x >=0 && x < n && y >= 0 && y < m){
            if (matrix[x][y] == target) return true;
            if (target > matrix[x][y]){
                x ++;
            }
            else{
                y --;
            }
        }
        return false;
    }
};
