class Solution {
    int numT(int n){
        int count = 0;
        if(n == 1) return count;
        while(n > 1){
            if(n % 2 == 1){
                n = 3*n + 1;
            }else{
                n /= 2;
            }
            count++;
        }
        return count;
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> arr;
        for(int i = lo; i <= hi; i++){
            arr.push_back({numT(i), i});
        }
        sort(arr.begin(), arr.end());
        return arr[k - 1].second;
    }
};