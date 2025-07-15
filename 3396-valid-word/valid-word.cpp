class Solution {
public:
    bool isValid(string word) {
        
        if(word.size() < 3)
            return false;
        
        bool vowel = false, consonant = false;

        for(char c : word)
            if( ('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ) {
                if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
                    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                        vowel = true;
                    else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                        vowel = true;
                    else
                        consonant = true;
            }
            else
                return false;
        
        return vowel && consonant;
    }
};