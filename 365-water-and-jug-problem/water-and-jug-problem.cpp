class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target > x + y) return false;
        return target % __gcd(x,y) == 0;
    }
};