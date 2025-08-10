class Solution {
public:
string countD(long long x){
    string cnt(10, '0');
    while(x > 0){
        cnt[x % 10]++;
        x /= 10;
    }
    return cnt;
}
    bool reorderedPowerOf2(int n) {
        string target = countD(n);
        for(int i = 0; i < 31; ++i){
            if(countD(1LL << i) == target) return true;
        }
        return false;
    }
};