// dp[i] -> i元素的子树有多少中bst
class Solution {
public:
    vector<int> memo;
    int numTrees(int n) 
    {
        memo = vector<int> (n+1, 0);
        return dp(n);
    }

    int dp(int i)
    {
        if(i==0||i==1)
            return 1;

        if(memo[i]!=0)
            return memo[i];

        int ans = 0;
        // 每个元素当作头结点 -> bst的左子树的元素全部小于根节点 右子树大于根节点
        for(int j=1;j<=i;j++)
        {
            // 左子树的有多少种 * 右子树有多少种
            ans += dp(j-1) * dp(i-j);
        }
        memo[i] = ans;
        return ans;
    }
};