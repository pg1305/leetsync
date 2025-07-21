class Solution {
public:
    string makeFancyString(string s) {
        string Fancy = "";
        int count = 1;
        for(int i = 0; i < s.size(); i++){
            if(i > 0 && s[i] == s[i - 1]){
                count++;
            }else{
                count = 1;
            }
            if(count <=2 ){
                Fancy += s[i];
            }
        }
        return Fancy;
    }
};