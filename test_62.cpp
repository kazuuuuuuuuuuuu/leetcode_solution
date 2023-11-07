#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                int ans = 0;
                cout << "1 dp[row][col]:" << dp[row][col] << endl; 
                if (row > 0) {
                    ans += dp[row - 1][col];
                    dp[row][col] += dp[row - 1][col];
                }
                if (col > 0) {
                    ans += dp[row][col - 1];
                    dp[row][col] += dp[row][col - 1];
                }
                //dp[row][col] = ans;
                cout << "2 dp[row][col]:" << dp[row][col] << endl; 
                cout << "3 ans:         " << ans << endl;
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
	Solution test;
	int m = 3;
	int n = 7;
	cout << test.uniquePaths(m, n);
}
