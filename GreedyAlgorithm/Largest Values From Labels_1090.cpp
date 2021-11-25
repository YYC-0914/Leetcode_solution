class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        // 直接使用贪心算法即可, 只不过有两个限制而已
        if (useLimit == 0) return 0;
        if (numWanted == 0) return 0;
        vector<pair<int, int>> a;
        for (int i = 0; i < values.size(); i++){
            a.push_back({values[i], labels[i]});
        }
        sort(a.begin(), a.end(), greater());
        // for (int i = 0; i < a.size(); i ++) cout << a[i].first << endl;
        unordered_map<int, int> label_cnt;
        int res = 0, cnt = 0;
        for (int i = 0; i < a.size(); i ++){
            if (cnt == numWanted) break;
            int val = a[i].first, idx = a[i].second;
            // cout << val << " " << idx << endl;
            if (!label_cnt.count(idx)){
                label_cnt[idx] = 1;
                res += val;
                cnt ++;
            }
            else{
                if (label_cnt[idx] < useLimit){
                    label_cnt[idx] ++;
                    res += val;
                    cnt ++;
                }
                else continue;
            }
        }
        // cout << label_cnt[0] << endl;
        return res;
    }
};
