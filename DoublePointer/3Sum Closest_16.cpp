class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // 本质上的过程和3sum是一模一样的
        // 还是使用双指针来优化搜索的过程
        int n = nums.size();
        int res = 0x3f3f3f3f;
        int diff = 0x3f3f3f3f;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i ++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int k = n - 1;
            for (int j = i + 1; j < n; j ++){
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                while (j < k && (nums[i] + nums[j] + nums[k] >= target)){
                    // cout << " i j k " << i << " " << j << " " << k << endl;
                    // cout << " nums[i] + nums[j] + nums[k] - target " << nums[i] + nums[j] + nums[k] - target << endl;
                    // cout << "_____________" << endl;
                    if (nums[i] + nums[j] + nums[k] - target < diff){
                        diff = nums[i] + nums[j] + nums[k] - target;
                        res = nums[i] + nums[j] + nums[k];
                    }
                    if (diff == 0) return res;
                    k --;
                } 
                if (j >= k) break;
                    // cout << " i j k " << i << " " << j << " " << k << endl;
                    // cout << " nums[i] + nums[j] + nums[k] - target " << target - (nums[i] + nums[j] + nums[k]) << endl;
                    // cout << "_____________" << endl;
                if (target - (nums[i] + nums[j] + nums[k]) < diff){
                    diff = target - (nums[i] + nums[j] + nums[k]);
                    res = nums[i] + nums[j] + nums[k];
                }
            }
        }
        return res;
    }  
};
