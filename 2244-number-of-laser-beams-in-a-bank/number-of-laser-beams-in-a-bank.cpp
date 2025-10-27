class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0, prev = 0;        
        for(string s : bank){
            int c = count(s.begin(), s.end(), '1');
            if(c > 0){
            res += (prev * c);
            prev = c;}
        }
        return res;
    }
};