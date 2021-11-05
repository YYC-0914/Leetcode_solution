class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_dist = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (i > max_dist) return false;
            if (max_dist >= n-1) return true;
            max_dist = max(max_dist, i + nums[i]);
        }
        return false;
    }
};
