class Solution {
public:
    void dfs(vector<string> &res, string str, int left, int right, int n){
        if (left == n && right == n){
            res.push_back(str);
            return;
        }

        if (left < n){
            dfs(res, str + '(', left + 1, right, n);
            
        }
        if (right < n && right < left){
            dfs(res, str + ')', left, right + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        // backtracking to generate all the possible parentthesis
        vector<string> res;
        dfs(res, "", 0, 0, n);
        return res;
    }
};
