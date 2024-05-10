// 斐波那契数列 
class Solution {
public:
    vector<int> memo; // memo数组 也可以用map记录
    int fib(int n) 
    {
        memo = vector<int> (n+1, -1);    
        return dp(n);
    }

    int dp(int i)
    {
        // base case
        if(i==0)
            return 0;
        if(i==1)
            return 1;
        if(memo[i]!=-1) // 检查memo数组是否已经计算过
            return memo[i];
        int ans = dp(i-1) + dp(i-2); // recurrence relation
        memo[i] = ans;
        return ans;
    }
};