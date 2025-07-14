class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int init = 100;
        int rem = init - purchaseAmount;
        int x = rem % 10;
        //return rem - x;
        if(x > 5){
            return rem + (10-x);
        }else{
            return rem - x;
        }
    }
};