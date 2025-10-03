class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        for(int emp = numBottles; emp >= numExchange; numExchange++){
            res++;
            emp -= numExchange - 1;
        }
        return res;
    }
};