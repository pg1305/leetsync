class Solution {
public:
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {
        long long d = 0;
        if(x < x1 || x > x2) d += min(pow(x1 - x, 2), pow(x2 - x, 2));
        if(y < y1 || y > y2) d += min(pow(y1 - y, 2), pow(y2 - y, 2));
        return d <= r*r;
    }
};