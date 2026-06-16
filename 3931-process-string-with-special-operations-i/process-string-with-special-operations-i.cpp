class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(char c: s){
            if(c == '#') res += res;
            else if(c == '*'){
                if(res.size()) res.pop_back();
            }
            else if(c == '%') res = string(res.rbegin(), res.rend());
            else res += c;
        }
        return res;
    }
};