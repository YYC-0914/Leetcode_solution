class Solution {
public:
    vector<int> add(vector<int> a, vector<int> b){
        vector<int> c;
        int carry = 0;
        for (int i = 0; i < a.size() || i < b.size(); i ++){
            if (i < a.size()) carry += a[i];
            if (i < b.size()) carry += b[i];
            c.push_back(carry % 10);
            carry /= 10;
        }
        if (carry > 0) c.push_back(carry);
        return c;
    }
    string addStrings(string num1, string num2) {
        // 不需要删去前导0
        vector<int> a, b;
        for (int i = num1.size() - 1; i >= 0; i --) a.push_back(num1[i] - '0');
        for (int i = num2.size() - 1; i >= 0; i --) b.push_back(num2[i] - '0');
        auto c = add(a, b);
        string ans;
        for (int i = c.size() - 1; i >= 0; i --)
            ans += char ('0' + c[i]);
        return ans;
    }
};
