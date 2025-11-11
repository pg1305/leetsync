class Solution {
public:
    int findIntegers(int n) {
        return 1 + countValidInts(1, n);
    }
    
private:
    int countValidInts(int integer, int limit) {
        if (integer > limit) {
            return 0;
        }
        if (integer & 1) {
            return 1 + countValidInts((integer << 1) | 0, limit);
        } else {
            return 1 + countValidInts((integer << 1) | 0, limit) + countValidInts((integer << 1) | 1, limit);
        }
    }
};