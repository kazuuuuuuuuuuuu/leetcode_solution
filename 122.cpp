// 股票问题 -> 一天买入 一天卖出 p[3]-p[0] -> 可分解为每天的相同操作 买入当天的 卖出前一天p[3] - p[2] + p[2] - p[1] + p[1] - p[0]
// 只收集当天交易的利差是正数的情况即可
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int ans = 0;
        for(int i=1;i<prices.size();i++)
        {
            ans += (prices[i] - prices[i-1]) > 0 ? (prices[i] - prices[i-1]) : 0;
        }    
        return ans;
    }
};
