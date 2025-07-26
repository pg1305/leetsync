class Solution {
public:
    int hammingWeight(int n) {
        vector<int> s;
        while(n > 0){
            s.push_back(n % 2);
            n /= 2;
        }
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 1) res++;
        }
        return res;
    }
};