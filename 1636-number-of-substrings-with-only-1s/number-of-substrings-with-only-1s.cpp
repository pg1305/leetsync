class Solution {
    const int mod = 1e9+7;
public:
    int numSub(string s) {
        int str = 0, res = 0;
        for(char c : s){
            if(c=='1'){
                res = (res + ++str) % mod;
            }else{
                str = 0;
            }
        }
        return res;
    }
};