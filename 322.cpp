// dp就是递归算法加保存结果 memoize
class Solution {
public:
    unordered_map<int, int> memo;
    vector<int> coins;
    int target;
    int coinChange(vector<int>& coins, int amount) 
    {
        target = amount;
        this->coins = coins;
        int ans = dp(amount);
        if(ans==target+1)
            return -1;
        return ans;    
    }

    //what dp returns and takes
    // 到达这个amount所需要的最小数量
    int dp(int amount)
    {
        if(amount==0)
            return 0;
        if(memo.find(amount)!=memo.end())
            return memo[amount];
        int ans = target+1;
        for(int &coin : coins)
        {
            if(amount-coin>=0)
            {
                ans = min(ans, dp(amount-coin) + 1);
            }
                
        }
        
        memo[amount] = ans;
        return ans;
    }
};






// 这个方法是对的但是一定会超时
class Solution {
public:
    int amount;
    vector<int> coins;
    int ans = INT_MAX;

    int coinChange(vector<int>& coins, int amount) 
    {
        if (amount == 0)
            return 0;
        this->amount = amount;
        this->coins = coins;
        backtrack(0, 0, 0);
        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }

    // 把 sum换成long long可以走的远一点 但是还是会面临超时的问题
    void backtrack(int i, int num, long long sum)
    {
        // base case
        if (num >= ans)
            return;
        // 先判断这一句 在判断下一个退出条件 
        // 不然的话有些正确答案会被排除
        if (sum == amount)
        {
            ans = min(ans, num);
            return;
        }        
        if (i == coins.size())
            return;

        while (sum <= amount)
        {
            // 更新到下一个坐标
            backtrack(i + 1, num, sum); 
            sum += coins[i];
            num ++;
        }
        
    }
};
