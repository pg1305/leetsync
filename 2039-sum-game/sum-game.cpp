class Solution {
public:
    bool sumGame(string s) {
        int n=s.length();
        int h=n>>1;
        int L=0,R=0;
        int lq=0,rq=0;
        for(int i=0;i<n;++i){
            if(i<h){
                if(s[i]=='?')
                    ++lq;
                else
                    L+=s[i]-'0';
            }else{
                if(s[i]=='?')
                    ++rq;
                else
                    R+=s[i]-'0';
            }
        }
        if(lq<rq){
            swap(L,R);
            swap(lq,rq);
        }
        int rem=lq-rq;
        if(rem==0)
            return L!=R;
        // println("{} {} {}",L,R,rem);
        if(L>=R)
            return true;
        int da=(rem+1)>>1;
        int db=rem>>1;
        int alice_max=L+da*9;
        if(alice_max>R)
            return true;
        int bob_max=L+db*9;
        // println("{} {}",alice_max,bob_max);
        //L<R
        return bob_max<R;
    }
};