class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        string s = "";
        bool n = num<0;
        if(n){
            num = -num;
        }
        while(num>0){
            s+= to_string(num%7);
            num/=7;
        }
        if(n){
            s+= '-';
        }

        reverse(s.begin(), s.end());
        return s;
    }
};