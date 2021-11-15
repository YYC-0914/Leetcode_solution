class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // double pointer && hashtable
        int a[300], res = 0;
        memset(a, 0, sizeof a);
        for (int i = 0, j = 0; i < s.size(); i++){
            a[s[i]] ++;
            while (a[s[i]] > 1){
                a[s[j]] --;
                j ++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
