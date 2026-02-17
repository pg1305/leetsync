class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int hr = 0; hr < 12; hr++){
            for(int min = 0; min < 60; min++){
                int bits = __builtin_popcount(hr) + __builtin_popcount(min);
                if(bits == turnedOn){
                    string tm = to_string(hr) + ":";
                    if(min < 10) tm += "0";
                    tm += to_string(min);
                    res.push_back(tm);  
                }
            }
        }
        return res;
    }
};