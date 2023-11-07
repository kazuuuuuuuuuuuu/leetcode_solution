#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, INT_MAX);

        for(int i=0;i<m;i++)
        {
            vector<int> curr = dp;
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                {
                    curr[j] = grid[i][j];
                    continue;
                }
                cout << "i, j: " << i << ",  " << j << endl;
                if(j>0)
                    curr[j] = min(curr[j], curr[j-1]);
                curr[j] += grid[i][j];
            }
            dp = curr;
        }
        return dp[n-1];
    }
};

int main()
{
	vector<vector<int>> grid {{1,3,1},{1,5,1},{4,2,1}};
	Solution solution;
	cout << solution.minPathSum(grid);
	
}
