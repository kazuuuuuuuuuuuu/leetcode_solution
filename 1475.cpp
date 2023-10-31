class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size(), 0);
        stack<int> price;
        for(int i =0;i<prices.size();i++)
        {
            while(!price.empty()&&prices[price.top()]>=prices[i])
            {
                int j = price.top();
                price.pop();
                ans[j] = prices[j] - prices[i];
            }
            price.push(i);   
        }

        while(!price.empty())
        {
            int j = price.top();
            price.pop();
            ans[j] = prices[j];
        }
        return ans;
    }

};