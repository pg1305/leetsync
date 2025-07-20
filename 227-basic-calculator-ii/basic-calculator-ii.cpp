class Solution {
public:
    int calculate(string s) {
        s.push_back('+'); 
        vector<int> stack;
        int num = 0, n = s.size();
        char op = '+';
        
        for(int i = 0; i < n; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == n - 1) {
                if (op == '+') {
                    stack.push_back(num);
                } else if (op == '-') {
                    stack.push_back(-num);
                } else if (op == '*') {
                    stack.back() *= num;
                } else if (op == '/') {
                    stack.back() = int(stack.back() / num);
                }
                op = c;
                num = 0;
            }
        }
        return accumulate(stack.begin(), stack.end(), 0);
    }
};
