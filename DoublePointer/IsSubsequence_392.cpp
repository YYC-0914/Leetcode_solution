class Solution {
public:
    bool isSubsequence(string s, string t) {
        // double pointer to solve this problem
        // using the idea of greedy algorithm, matching each character of the mode string with the first appropriate character in the large string
        int i = 0;
        for (int j = 0; j < t.size(); j ++){
            if (i < s.size() && s[i] == t[j]) i ++;
        }
        return i == s.size();
    }
};
