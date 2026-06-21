class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mx = 0;
        vector<int> freq(1e5 + 1, 0);
        for(int c: costs){
            freq[c]++;
            mx = max(mx, c);
        }
        int cnt = 0;
        for(int i = 1; i <= mx; i++){
            int f = freq[i];
            if(f == 0) continue;
            int buy = min(coins/i, f);
            if(buy == 0) break;
            cnt += buy;
            coins -= buy * i;
        }
        for(int c: costs) freq[c] = 0;
        return cnt;

        
    }
};