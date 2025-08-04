class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int st = 0, maxLen = 0;
        unordered_map<int, int> basket;
        for(int end = 0; end < fruits.size(); ++end){
            basket[fruits[end]]++;
            while(basket.size()>2){
                basket[fruits[st]]--;
                if(basket[fruits[st]] == 0){
                    basket.erase(fruits[st]);
                }
                st++;
            }
            maxLen = max(maxLen, end - st + 1);
        }
        return maxLen;
    }
};