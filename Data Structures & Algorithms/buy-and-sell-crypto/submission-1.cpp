class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = 0; int b = 1;
        int max = 0;

        while(a < prices.size() && b < prices.size()){
            max = std::max(max, prices[b] - prices[a]);
            if(prices[a] > prices[b]){
                a = b; b++;
            }
            else if(prices[a] <= prices[b]){
                b++;
            }
        }

        return max;
    }
};
