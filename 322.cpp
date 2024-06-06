class Solution {
public:
    vector<int> coins;
    vector<int> memo;
    int coinChange(vector<int>& coins, int amount) 
    {
        this->coins = coins;
        memo = vector<int> (amount+1, -1);
        int ans = dp(amount);
        if(ans==INT_MAX) return -1;
        return ans;
    }

    int dp(int curr)
    {
        if(curr==0) return 0;
        if(curr<0) return INT_MAX;

        if(memo[curr]!=-1) return memo[curr];
        int ans = INT_MAX;
        for(int coin : coins)
        {
            int result = dp(curr-coin);
            if(result==INT_MAX)
            {
               continue;
            }
            ans = min(ans, dp(curr-coin)+1);    
        }
        memo[curr] = ans;
        return ans;
    }
};




// backtrack这个方法是对的但是一定会超时
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



