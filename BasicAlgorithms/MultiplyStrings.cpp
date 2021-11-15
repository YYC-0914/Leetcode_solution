class Solution {
public:
        void trimzero(vector<int> &a){
            while (a.size() > 1 && a.back() == 0) a.pop_back();
        } 
    
        vector<int> mul(vector<int> a, vector<int> b){
            int n = a.size(), m = b.size();
            vector<int> c(n+m);
            for (int i = 0; i < a.size(); i ++)
                for (int j = 0; j < b.size(); j ++)
                    c[i+j] += a[i] * b[j];
            for (int i = 0, carry = 0; i < c.size(); i++){
                carry += c[i];
                c[i] = carry % 10;
                carry /= 10;
            }
            trimzero(c);
            return c;
        }
    
    string multiply(string num1, string num2){
        // 双高精度的乘法
        vector<int> a, b;
        for (int i = num1.size() - 1; i >= 0; i --) a.push_back(num1[i] - '0');
        for (int i = num2.size() - 1; i >= 0; i --) b.push_back(num2[i] - '0');
        vector<int> c;
        c = mul(a,b);
        string ans;
        for (int i = c.size() - 1; i >= 0; i --){
            ans += char ('0' + c[i]);
        }
        return ans;
    }
};
