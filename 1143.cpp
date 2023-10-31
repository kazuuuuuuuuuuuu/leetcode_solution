// two dimensional dp 
class Solution {
public:
    string text1;
    string text2;
    vector<vector<int>> memo;
    int longestCommonSubsequence(string text1, string text2) 
    {
        this->text1 = text1;
        this->text2 = text2;
        memo = vector<vector<int>> (text1.size(), vector<int> (text2.size(), -1));
        return dp(0, 0);
    }

    // what the dp takes and returns
    int dp(int i, int j)
    {
        if(i==text1.size()||j==text2.size())
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];

        int ans = 0;
        if(text1[i]==text2[j])
            ans = 1 + dp(i+1, j+1);
        else
            ans = max(dp(i, j+1), dp(i+1, j));
        memo[i][j] = ans;
        return ans;
    }
};

// bottom up
// need to iterate from the base case