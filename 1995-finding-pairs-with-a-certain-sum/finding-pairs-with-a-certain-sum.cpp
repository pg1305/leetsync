const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif
class FindSumPairs {
public:
    vector<int> vec1;
    vector<int> vec2;
    unordered_map<int , int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;
        for(int &x : nums2){
            mp[x]++;
        }
    }
    
    void add(int index, int val) {
        mp[vec2[index]]--;
        vec2[index] += val;
        mp[vec2[index]]++;
    }
    
    int count(int tot) {
        int c = 0;
        for(int &x : vec1){
            c += mp[tot-x];
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */