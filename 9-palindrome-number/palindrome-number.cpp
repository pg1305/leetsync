class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long temp=x,newx=0;
        while(temp!=0){
            int digit=temp%10;
            newx=(newx*10)+digit;
            temp/=10;
        }
        return newx==x;
    }
};