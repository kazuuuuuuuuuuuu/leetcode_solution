class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        // the sort function will lead to a non-decreasing array
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(int cost : costs)
        {
            if(coins>=cost)
            {
                coins -= cost;
                ans ++;
            }
            else
                break;
        }    
        return ans;
        
    }
};