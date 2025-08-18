class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;
        int sumL = 0, sumR = 0;
        int countL = 0, countR = 0;
        for(int i = 0; i < half; i++){
            if(num[i] == '?') countL++;
            else sumL += num[i] - '0';
        }
        for(int i = half; i < n; i++){
            if(num[i] == '?') countR++;
            else sumR += num[i] - '0';
        }
        if((countL + countR) % 2 == 1) return true;
        int del = sumL - sumR;
        int delQ = countR - countL;
        return del*2 != delQ*9;
    }
};