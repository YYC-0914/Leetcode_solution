class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //  排序后使用双指针，不要忘记去重的操作
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i ++){
            // 第一层指针的去重操作
            if (i > 0 && nums[i] == nums[i-1]) continue;
            // 最后的两层使用双指针的技巧可以优化成O(n)的时间复杂度
            int k = n - 1;
            int target = -nums[i];
            for (int j = i + 1; j < n; j ++){
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                while (k > j && nums[j] + nums[k] > target) k --;
                if (k == j) break;
                if (nums[j] + nums[k] == target) res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};
