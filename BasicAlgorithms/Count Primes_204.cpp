class Solution {
public:
    int countPrimes(int n) {
        vector<bool> st(n+1);
        int cnt = 0;
        for (int i = 2; i < n; i ++){
            if (! st[i]) cnt ++;
            for (int j = i; j < n; j += i) st[j] = true;
        }
        return cnt;
    }
};
