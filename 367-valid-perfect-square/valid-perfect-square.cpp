class Solution {
public:
    bool isPerfectSquare(int num) {
        int st = 1;
        int end = num;
        while(st <= end){
            long mid = st + (end - st)/2;
            long ans = mid*mid;
            if(ans == num) return true;
            if(ans < num) st = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};