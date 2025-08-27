class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<int> copy(n);
        copy[n - 1] = satisfaction[n - 1];
        for(int i = n - 2; i >= 0; i--){
            copy[i] = satisfaction[i] + copy[i + 1];
        }
        int idx = -1;
        for(int i = 0; i < n; i++){
            if(copy[i] >= 0){
                idx = i;
                break;
            }
        }
        int ans = 0;
        if(idx != -1){
            int k = 1;
            for(int i = idx; i < n; i++){
                ans += k*satisfaction[i];
                k++;
            }
        }
        return ans;
    }
};