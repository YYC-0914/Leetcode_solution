class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // 本质上是一个双指针找到两个list中左端点最小的interval
        // 然后合并的过程其实和56_merge interval一模一样

        int n1 = firstList.size(), n2 = secondList.size();
        if (! n1) return secondList;
        if (! n2) return firstList;
        vector<vector<int>> res;
        int idx1 = 0, idx2 = 0;
        int cur_l = -1, cur_r = -1;
        while (idx1 < n1 || idx2 < n2){
            int l, r;
            if (idx1 == n1){
                l = secondList[idx2][0];
                r = secondList[idx2][1];
                idx2 ++;
            }
            else if (idx2 == n2){
                l = firstList[idx1][0];
                r = firstList[idx1][1];
                idx1 ++;
            }
            else{
                if (firstList[idx1][0] < secondList[idx2][0]){
                    l = firstList[idx1][0];
                    r = firstList[idx1][1];
                    idx1 ++;
                }
                else{
                    l = secondList[idx2][0];
                    r = secondList[idx2][1];
                    idx2 ++;
                }
            }
 
            if (l > cur_r){
                if (cur_l != -1){
                    res.push_back({cur_l, cur_r});
                }
                cur_l = l;
                cur_r = r;
            }
            else{
                cur_r = max(cur_r, r);
            }
        }
        res.push_back({cur_l, cur_r});
        return res;
    }
};
