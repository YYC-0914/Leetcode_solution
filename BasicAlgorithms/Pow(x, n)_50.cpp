class Solution {
public:
    double myPow(double x, int n) {
        // 快速幂的应用
        // 用n的二进制表达来处理幂次
        // 正整数的情况
        double res = 1, product;
        if (n >= 0) product = x;
        else product = 1 / x;
        long long k = n;
        if (k < 0) k = -k;
        for (int i = 0; i < 32; i ++){
            if ((k >> i) & 1) res *= product;
            product = product * product;
        }
        return res;
    }
};
