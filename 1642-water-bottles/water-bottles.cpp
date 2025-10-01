class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int tot = numBottles;
        int emp = numBottles;
        while(emp >= numExchange){
            int newB = emp / numExchange;
            tot += newB;
            emp = emp % numExchange + newB;
        }
        return tot;
    }
};