class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int x = (i >= 0) ? a[i--] - '0' : 0;
            int y = (j >= 0) ? b[j--] - '0' : 0;

            int sum = x ^ y ^ carry;                 // XOR for sum
            carry = (x & y) | (y & carry) | (x & carry);  // carry logic
            result.push_back(sum + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
