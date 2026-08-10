class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> C(A.size());
        for(int i = 0; i < A.size(); ++i){
            int count = 0;
            for(int a = 0; a <= i; ++a){
                for(int b = 0; b <= i; ++b){
                    if(A[a] == B[b]){
                        ++count;
                        break;
                    }
                }
            }
            C[i] = count;
        }
        return C;
    }
};