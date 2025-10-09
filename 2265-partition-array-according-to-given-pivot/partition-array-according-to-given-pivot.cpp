class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        std::vector<int> G,L;
        G.reserve(nums.size());
        L.reserve(nums.size());
        int NPivot=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            {
                L.emplace_back(nums[i]);
            }
            else if(nums[i] == pivot){
                NPivot++;
            }
            else{
                G.emplace_back(nums[i]);
            }
        }

        while(NPivot>0){
            L.emplace_back(pivot);
            NPivot--;
        }
        L.insert(L.end(),std::make_move_iterator(G.begin()),std::make_move_iterator(G.end()) );
        return std::move(L);
    }
};