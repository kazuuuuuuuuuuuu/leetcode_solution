class Solution {
public:
    vector<vector<vector<int>>> memo;
    vector<string> strs;

    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int length = strs.size();
        memo = vector<vector<vector<int>>> (m+1, vector<vector<int>> (n+1, vector<int> (length, -1)));
        this->strs = strs;
        return dp(m, n, length-1);
    }

    // dp 含义在重量为(m, n)的状态下 该背包最多装下多少东西
    int dp(int m, int n, int i)
    {
        string str = strs[i];
        int num_0 = 0; 
        int num_1 = 0;
        for(char a : str)
        {
            if(a=='0')
                num_0 ++;
            else
                num_1 ++;
        }


        // 到达最后一个元素
        if(i==0)
        {
            if(m>=num_0&&n>=num_1)
                return 1;
            else
                return 0;
        }

        if(memo[m][n][i]!=-1)
            return memo[m][n][i];

        int ans = 0;
        // 当前元素可以装下 取最大
        if(m>=num_0&&n>=num_1)
        {
            ans = max(dp(m, n, i-1), dp(m-num_0, n-num_1, i-1)+1);
        }
        // 不能装下 跳过这个元素
        else
        {
            ans = dp(m, n, i-1);
        }
        memo[m][n][i] = ans;
        return ans;
    }
};


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int length = strs.size();
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>> (length+1, vector<vector<int>> (m+2, vector<int> (n+2, 0)));
        for(int i=length-1;i>=0;i--)
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    string str = strs[i];
                    int curr_m = 0;
                    int curr_n = 0;
                    for(char a : str)
                    {
                        if(a=='0')
                            curr_m ++;
                        else
                            curr_n ++;
                    }
                    int ret = dp[i+1][j][k];
                    if(j>=curr_m&&k>=curr_n)
                    {
                        ret = max(ret, 1 + dp[i+1][j-curr_m][k-curr_n]);
                    }
                    dp[i][j][k] = ret;
                }
            }
        }
        return dp[0][m][n];

    }
};


