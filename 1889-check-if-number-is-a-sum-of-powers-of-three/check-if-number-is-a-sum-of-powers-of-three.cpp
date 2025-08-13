class Solution {
public:
    bool checkPowersOfThree(int n) {
        int exp = 0;
        while(pow(3, exp) <= n){
            exp++;
        }
        while(n > 0){
            if(n >= pow(3, exp)) n-= pow(3, exp);
            if(n >= pow(3, exp)) return false;
            exp--;
        }
        return true;
    }
};