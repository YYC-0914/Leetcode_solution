class Solution {
public:
    int findLHS(vector<int>& nums) {
        // 因为寻找的是subsequence，所以我们可以改变nums的顺序，这并不会影响我们的答案
        sort(nums.begin(), nums.end());
        int val = 0;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++){
            while (nums[i] - nums[idx] > 1 && idx < i) idx ++;
            if (nums[i] - nums[idx] == 1) val = max(val, i - idx + 1);
        }
        return val;
    }
};
