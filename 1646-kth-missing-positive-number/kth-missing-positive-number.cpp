class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size();
        while(left < right){
            int mid = (left + right)/2;
            int miss = arr[mid] - mid - 1;
            if(miss < k){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left + k;
    }
};