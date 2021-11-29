class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> count;
        int cnt = 1;
        for (int i = 1; i < s.size(); i ++){
            if (s[i] == s[i-1]) cnt ++;
            else{
                count.push_back(cnt);
                cnt = 1;
            }
        }
        count.push_back(cnt);
        int res = 0;
        for (int i = 0; i < count.size() - 1; i ++){
            // cout << min(count[i], count[i+1]);
            res += min(count[i], count[i+1]);
        }
        return res;
    }
};
