class Solution { 
    bool isVowel(char c){
        return c == 'a' || c == 'e' ||c == 'i' ||c == 'o' ||c == 'u' ||c == 'A' ||c == 'E' ||c == 'I' ||c == 'O' ||c == 'U';
    }
public:
    string sortVowels(string s) {
        string vowels;
        for(char c : s){
            if(isVowel(c)) vowels += c;
        }
        sort(vowels.begin(), vowels.end());
        int k = 0;
        string res;
        for(char c : s){
            if(isVowel(c)){
                res += vowels[k];
                k++;
            }else res += c;
        }
        return res;
    }
};