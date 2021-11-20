class Solution {
public:
    int binary_search(vector<int> &nums, int x){
        int l = 0, r = nums.size() - 1;
        while (l < r){
            int mid = l + r >> 1;
            if (nums[mid] >=  x) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        // 可以使用二分或者使用位运算来解决
        // 显然二分要稍微快一点
        // int sum = 0;
        // for (int i = 0; i < nums.size(); i ++){
        //     sum ^= nums[i];
        // }
        // return sum;
        
        
        // 找到最小的idx使得nums[idx] >= target
        // 如果 n - idx 是奇数，那么 l = mid, 反之在 r = mid - 1
        // 且一定要记住在整数二分中 l = mid -> mid = l + r + 1 >> 1, r = mid -> mid = l + r >> 1
        int n = nums.size() - 1;
        int l = nums[0], r = nums[n];
        while (l < r){
            int mid = l + r + 1 >> 1;
            int idx = binary_search(nums, mid);
            if (idx & 1) r = mid - 1;
            else l = mid;
        }
        return l;
    }
};
