class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int rectW1 = abs(ax2 - ax1);
        int rectW2 = abs(bx2 - bx1);
        int rectL1 = abs(ay2 - ay1);
        int rectL2 = abs(by2 - by1);
        int ar1 = rectL1 * rectW1;
        int ar2 = rectL2 * rectW2;
        int comL = max(0 , min(ax2, bx2) - max(ax1, bx1));
        int comW = max(0, min(ay2, by2) - max(ay1, by1));
        int comAr = comL * comW;
        return ar1 + ar2 - comAr;
    }
};