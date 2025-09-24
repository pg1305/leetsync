class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        if(numerator == 0) return "0";
        if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) res += "-";
        long divN = labs(numerator);
        long divD = labs(denominator);
        int hcf = __gcd(divN, divD);
        divN /= hcf;
        divD /= hcf;
        long quot = divN/divD;
        long rem = divN%divD;
        res += to_string(quot);
        if(rem == 0) return res;
        res += ".";
        unordered_map<long, int> map;
        while(rem != 0){
            if(map.count(rem)){
                res.insert(map[rem], "(");
                res += ")";
                return res;
            }
            map[rem] = res.size();
            rem *= 10;
            res += to_string(rem / divD);
            rem %= divD;
        }
        return res;
    }
};