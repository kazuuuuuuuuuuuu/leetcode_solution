class Solution {
public:
    vector<int> piles;
    int n;
    vector<vector<unordered_map<int, int>>> memo;
    int stoneGameII(vector<int>& piles) 
    {
        this->piles = piles;
        n = piles.size();
        memo = vector<vector<unordered_map<int, int>>> (n, vector<unordered_map<int, int>> (2, unordered_map<int, int> {}));

        return dp(0, 1, 1);
    }

    // 返回alice可以拿到的最大的值
    // 目前我所做过的dp的题 返回值一般都只是一个
    int dp(int i, int alice_turn, int m)
    {
        if(i==n)
            return 0;
        if(memo[i][alice_turn].find(m)!=memo[i][alice_turn].end())
        {
            return memo[i][alice_turn][m];
        }
        // i在之后会被修改 注意提前保存
        int i_origin = i;
        // alice 找最大
        if(alice_turn==1)
        {
            int ret = 0;
            int sum = 0;
            for(int j=1;j<=2*m;j++)
            {
                if(i<n)
                {
                    sum += piles[i];
                    i ++;
                    if(sum+dp(i, 0, max(j, m))>ret)
                    {
                        ret = sum + dp(i, 0, max(j, m));
                    }
                }
            }
            memo[i_origin][alice_turn][m] = ret;
            return ret;
        }

        // bob取完之后找alice最小的值就行了
        // 像一个通道直接把下一个alice的状态的返回值传回去
        else
        {
            int ret = INT_MAX;
            for(int j=1;j<=2*m;j++)
            {
                if(i<n)
                {
                    // 取一个 i++
                    i ++;
                    if(dp(i, 1, max(j, m))<ret)
                    {
                        ret = dp(i, 1, max(j, m));
                    }
                }
            }
            memo[i_origin][alice_turn][m] = ret;
            return ret;
        }
    }
};