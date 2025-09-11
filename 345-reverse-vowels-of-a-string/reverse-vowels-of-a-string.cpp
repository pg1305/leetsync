class Solution {
public:
    string reverseVowels(string s) {
        int st = 0 , end = s.length()-1 ;

        while(st<end){
        if(tolower(s[st])!='a' && tolower(s[st])!='e' && tolower(s[st])!='i' && tolower(s[st])!='o' &&      tolower(s[st])!='u' ){
            st++ ;
        }
        else if (tolower(s[end])!='a' && tolower(s[end])!='e' && tolower(s[end])!='i' && tolower(s[end])!='o' && tolower(s[end])!='u' ){
            end-- ;
        }
            else{
                swap(s[st] , s[end]) ;
                st++ ;
                end-- ;
            }
                }   
                return s ;     
            }
};