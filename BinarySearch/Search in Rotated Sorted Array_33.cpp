class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 这里distinct value 还是特别有用的，这样的话就可以使用二分查找来处理这个问题了
        // 每次二分，总有边是有序的，所以我们是可以判断target在数组中的位置的
        if (target == nums[0]) return 0;
        else if (target == nums[nums.size() - 1]) return nums.size() - 1;
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = l + r >> 1;
            // cout << "mid " << mid << " l " << l << " r " << r << endl;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[0]){
                // mid 在有序的当中
                if (target >= nums[0]){
                    if (nums[mid] > target) r = mid - 1;
                    else l = mid + 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if (target >= nums[0]) r = mid - 1;
                else{
                    if (nums[mid] > target) r = mid - 1;
                    else l = mid + 1;
                }
            }
        }
        return -1;
    }
};
