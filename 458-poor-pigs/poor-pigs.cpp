class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int cnt = 0;
        int attempt = minutesToTest / minutesToDie;
        while(pow((attempt + 1), cnt) < buckets) cnt++;
        return cnt;
    }
};