class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1. 从后往前找到第一个(i, i+1) pair使得其事升序的
        // 2. 此时注意(i, end) 是降序的
        // 3. 从后向前查找第一个nums[k] > nums[i]  并且交换
        // 4. 交换后reverse (i, end)
        for (int i = nums.size() - 2; i >= 0; i --){
            if (nums[i] < nums[i+1]){
                for (int j = nums.size() - 1; j > i; j --){
                    if (nums[j] > nums[i]){
                        swap(nums[i], nums[j]);
                        reverse(nums.begin() + i + 1, nums.end());
                        return ;
                    }
                }                
            }
        }
        reverse(nums.begin(), nums.end());
        return ;
    }
};
