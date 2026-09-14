class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int tx1 = -1, tx2 = -1, ty1 = -1, ty2 = -1;
        if(ax1 >= bx1 && ax1 < bx2){
            tx1 = ax1;
        }

        if(bx1 >= ax1 && bx1 < ax2){
            tx1 = bx1;
        }

        if(ax2 <= bx2 && ax2 > bx1){
            tx2 = ax2;
        }

        if(bx2 <= ax2 && bx2 > ax1){
            tx2 = bx2;
        }

        if(ay1 >= by1 && ay1 < by2){
            ty1 = ay1;
        }

        if(by1 >= ay1 && by1 < ay2){
            ty1 = by1;
        }

        if(ay2 <= by2 && ay2 > by1){
            ty2 = ay2;
        }

        if(by2 <= ay2 && by2 > ay1){
            ty2 = by2;
        }
        int areaA = (ax2- ax1) * (ay2 - ay1);
        int areaB = (bx2- bx1) * (by2 - by1);
        int areaT = (tx2- tx1) * (ty2 - ty1);

        return areaA + areaB - areaT;
        
    }
};