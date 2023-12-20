class Solution {
public:
    int length;
    vector<string> strs;
    vector<vector<vector<int>>> memo;

    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        this->strs = strs;
        length = strs.size();
        memo = vector<vector<vector<int>>> (length, vector<vector<int>> (m+1, vector<int> (n+1, -1)));
        return dp(0, m, n);
    }

    // return the answer to the original problem
    int dp(int i, int m, int n)
    {
        if(i==length)
            return 0;
        if(memo[i][m][n]!=-1)
            return memo[i][m][n];

        //cout << "i:" << i << " m:" << m << " n:" << n <<  endl; 
        string curr = strs[i];
        int curr_m = 0;
        int curr_n = 0;
        for(auto a : curr)
        {
            if(a=='0')
                curr_m ++;
            else
                curr_n ++;
        }

        int ret = dp(i+1, m, n);
        if(curr_m<=m&&curr_n<=n)
            ret = max(ret, 1+dp(i+1, m-curr_m, n-curr_n));

        memo[i][m][n] = ret;

        return ret; 
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