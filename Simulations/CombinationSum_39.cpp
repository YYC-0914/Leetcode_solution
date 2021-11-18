class Solution {
public:
    void dfs(vector<vector<int>> & res, vector<int> & cur, int idx, vector<int>& nums, int target){
        // 这里在nums之前加一个引号会快好多好多好多好神奇！
        if (idx >= nums.size()) return;
        if (target == 0){
            res.emplace_back(cur);
            return ;
        }
        // 直接跳过
        dfs(res, cur, idx + 1, nums, target);
        // 选择了当前的数
        if (target - nums[idx] >= 0){
            cur.emplace_back(nums[idx]);
            dfs(res, cur, idx, nums, target - nums[idx]);
            cur.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 这是一道非常典型的dfs question
        // dfs 可以剪枝
        // 从大到小枚举
        vector<vector<int>> res;
        vector<int> cur;
        // sort(candidates.begin(), candidates.end(), greater<>());

        dfs(res, cur, 0, candidates, target);
        
        return res;
    }
};
