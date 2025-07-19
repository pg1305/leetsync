class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> map;
        for(char c : s){
            map[c]++;
        }
        int maxOdd = 1, minEven = s.size();
        for(const auto& [_,val] : map){
            if(val % 2 == 1){
                maxOdd = max(maxOdd, val);
            }else{
                minEven = min(minEven, val);
            }
        }
        return maxOdd - minEven;
    }
};