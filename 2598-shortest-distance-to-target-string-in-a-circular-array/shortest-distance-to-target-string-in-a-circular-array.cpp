class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int res = n;
        for(int i = 0; i < n; i++){
            if(words[i] == target){
                int dist = abs(i - startIndex);
                res = min(res,min(dist, n - dist));
            }
        }
        return res < n ? res:-1;
    }
};