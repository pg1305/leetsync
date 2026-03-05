class Solution {
public:
    int minOperations(string s) {
        int b0 = 0;
        int b1 = 0;
        for(int i = 0; i < s.size(); i++){
            if(i % 2 == 0){
                if(s[i] == '0') b1++;
                else b0++;
            }else{
                if(s[i] == '1') b1++;
                else b0++;
            }
        }
        return min(b0, b1);
    }
};