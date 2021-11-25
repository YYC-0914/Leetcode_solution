class Solution {
public:
    int strStr(string haystack, string needle) {
        // kmp算法一模一样地写一遍当练习
        // 这里有点恶心的就是string是从0开始的
        int n = haystack.size(), m = needle.size();
        if (n == 0){
            if (m == 0) return 0;
            else return -1;
        }
        if (m == 0) return 0;
        int ne[m+1];
        memset(ne, 0, sizeof ne);
        for (int i = 1, j = 0; i < m; i ++){
            while (j > 0  && needle[i] != needle[j]) j = ne[j-1];
            if (needle[i] == needle[j]) j ++;
            ne[i] = j;    
        }
        for (int i = 0, j = 0; i < n; i ++){
            while (j > 0  && haystack[i] != needle[j]) j = ne[j-1];
            if (haystack[i] == needle[j]) j++;
            if (j == m){
                return i - m + 1;
            }
        }
        return -1;
    }
};
