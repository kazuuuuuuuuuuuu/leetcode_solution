class Solution {
public:
    vector<int> nums1;
    vector<int> nums2;
    vector<vector<int>> memo;
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        memo = vector<vector<int>> (nums1.size(), vector<int> (nums2.size(), -1));
        return dp(0, 0);
    }

    int dp(int i_start, int j_start)
    {
        if(i_start==nums1.size()||j_start==nums2.size())
            return 0;
        if(memo[i_start][j_start]!=-1)
            return memo[i_start][j_start];

        int ans = dp(i_start+1, j_start+1);
        if(nums1[i_start]==nums2[j_start])
        {
            ans ++;
        }
        ans = max(ans, dp(i_start, j_start+1));
        ans = max(ans, dp(i_start+1, j_start));
        memo[i_start][j_start] = ans;
        return ans;
    }
};

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> dp(nums1.size()+1, vector<int> (nums2.size()+1, 0));
        for(int i=nums1.size()-1;i>=0;i--)
        {
            for(int j=nums2.size()-1;j>=0;j--)
            {
                int ans = dp[i+1][j+1];
                if(nums1[i]==nums2[j])
                    ans ++;
                ans = max(ans, dp[i][j+1]);
                ans = max(ans, dp[i+1][j]);
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};