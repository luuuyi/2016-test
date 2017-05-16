class Solution {
private:
    int findMaxValByOne(vector<int> prices, int start, int end){
        if(start>=end)  return 0;
        int max_profit=0, min_val = INT_MAX;
        for(int i=start;i<=end;i++){
            min_val = min(min_val,prices[i]);
            max_profit = max(max_profit,prices[i]-min_val);
        }
        return max_profit;
    }
public:
    /**
     * 计算你能获得的最大收益
     * 
     * @param prices Prices[i]即第i天的股价
     * @return 整型
     */
    int calculateMax(vector<int> prices) {
        int lens = prices.size();
        int max_profit = 0;
        for(int i=0;i<lens;i++){
            max_profit = max(max_profit, findMaxValByOne(prices,0,i)+findMaxValByOne(prices,i+1,lens-1));
        }
        return max_profit;
    }
};