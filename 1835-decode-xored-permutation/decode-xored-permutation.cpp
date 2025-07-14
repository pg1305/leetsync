class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
    int n = encoded.size() + 1;
    int total = 0;
    vector<int> decoded(n);
    for(int i = 1; i <=n ; i++){
        total^=i;
    }
    int odd_xor = 0;
    for(int i = 1; i < encoded.size(); i+=2){
        odd_xor^=encoded[i];
    }
    decoded[0] = total ^ odd_xor;
    for(int i = 0; i < encoded.size(); i++){
        decoded[i+1]= decoded[i]^encoded[i];
    }
    return decoded;
    }
};