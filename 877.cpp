// 这道题用贪婪算法不可以 因为每次选局部最优解 
// 最终叠加起来不一定是全局最优解
// 使用动态规划
class Solution {
public:
    vector<int> piles;
    vector<vector<int>> memo;
    bool stoneGame(vector<int>& piles) 
    {
        this->piles = piles;
        int n = piles.size();
        memo = vector<vector<int>> (n, vector<int> (n, INT_MAX));
        return dp(0, n-1, 1)>0;
    }

    // 用index start和end代表被考虑的剩余的piles而不是真的piles
    // 动态规划常用索引用来在输入数组上移动
    // 返回的是得分差
    int dp(int start, int end, int alice_turn)
    {
        if(start>end)
            return 0;
        // 是爱丽丝的回合 recurrence relation比较简单
        // 两个方案里选最大的
        if(memo[start][end]!=INT_MAX)
            return memo[start][end];
        int ret1;
        int ret2;
        if(alice_turn==1)
        {
            ret1 = piles[start] + dp(start+1, end, 0);
            ret2 = piles[end] + dp(start, end-1, 0);
            return memo[start][end] = max(ret1, ret2);
        }
        // bob的回合要用相反的方式思考 他的目的是让返回的值最小
        else
        {
            ret1 = -piles[start] + dp(start+1, end, 1);
            ret2 = -piles[end] + dp(start, end-1, 1);
            return memo[start][end] = min(ret1, ret2);
        }
        
    }
};