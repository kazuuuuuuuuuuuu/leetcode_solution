// 两堆重量差最小 -> 找重量完全相同的两堆  -> 重量和价值相同 一半重量的背包最大价值是多少
class Solution {
public:
    // 使用map来当memo数组 因为memo数组一个维度的过大
    unordered_map<int, unordered_map<int, int>> memo;
    vector<int> stones;
    int lastStoneWeightII(vector<int>& stones) 
    {
        int sum = 0;
        for(int stone : stones)
        {
            sum += stone;
        }    
        int target = sum / 2;

        this->stones = stones;
        int n = stones.size();
        int result = sum - dp(n-1, target) * 2;
        return result;
    }

    int check(int i, int j)
    {
        if(memo.find(i)!=memo.end())
        {
            if(memo[i].find(j)!=memo[i].end())
            {
                return memo[i][j];
            }
        }
        return -1;
    }

    int dp(int i, int curr_weight)
    {
        if(curr_weight==0)
            return 0;
        if(i==0&&curr_weight<stones[0])
            return 0;
        if(i==0&&curr_weight>=stones[0])
            return stones[0];

        int ans = check(i, curr_weight);
        if(ans!=-1)
            return ans;

        ans = 0;
        if(curr_weight>=stones[i])
        {
            ans = max(dp(i-1, curr_weight), dp(i-1, curr_weight-stones[i])+stones[i]);
        } 
        else
        {
            ans = dp(i-1, curr_weight);
        }

        memo[i][curr_weight] = ans;
        return ans;
    }
};