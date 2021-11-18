class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int> &cur, vector<int> &nums, vector<bool> &st, int cnt){
        if (cnt == nums.size()){
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i ++){
            if (! st[i]){
                if (i >= 1 && (nums[i] == nums[i-1]) && st[i-1] == false) continue;
                cur.push_back(nums[i]);
                st[i] = true;
                dfs(res, cur, nums, st, cnt + 1);
                cur.pop_back();
                st[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 1){
                res.push_back(nums);
                return res;
        }

        vector<int> cur;
        vector<bool> st(nums.size() + 1);
        sort(nums.begin(), nums.end());
        dfs(res, cur, nums, st, 0);
        return res;
    }
};
