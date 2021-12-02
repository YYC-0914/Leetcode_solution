class Solution {
public:
    int countPrimes(int n) {
        // // 埃氏筛法
        // vector<bool> st(n+1);
        // int cnt = 0;
        // for (int i = 2; i < n; i ++){
        //     if (! st[i]) cnt ++;
        //     for (int j = i; j < n; j += i) st[j] = true;
        // }
        // return cnt;
        // 线性筛法
        vector<bool> st(n+1);
        vector<int> prime;
        int cnt = 0;
        for (int i = 2; i < n; i ++){
            if (! st[i]){
                cnt ++;
                prime.push_back(i);
            }
            for (int j = 0; j < prime.size() && i * prime[j] < n; j ++){
                st[i * prime[j]] = true;   
                if (i % prime[j] == 0) break;     
            }
        }
        return prime.size();
    }
};
