class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0){
            return 1;
        }
        int res = 10;
        int unq = 9, avl = 9;
        for(int i = 2; i <= n && avl > 0; i++){
            unq *= avl;
            res += unq;
            avl--;
        }
        return res;
    }
};