class Solution {
public:
    void permute(vector<vector<int>> &res, vector<int> &cur, vector<int> &nums, vector<bool> &st, int cnt){
        if (cnt == nums.size()){
            res.push_back(cur);
            return ;
        }
        for (int i = 0; i < nums.size(); i++){
            if (! st[i]){
                cur.push_back(nums[i]);
                st[i] = true;
                permute(res, cur, nums, st, cnt + 1);
                cur.pop_back();
                st[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> st(nums.size() + 1);
        permute(res, cur, nums, st, 0);
        return res;        
    }
};
