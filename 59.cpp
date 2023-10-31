// record starting point and offset

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        int x_start = 0;
        int y_start = 0;
        int offset = 1;
        int count = 1;
        int i, j;

        vector<vector<int>> ans(n, vector<int> (n));



        int level = 1;
        while(level<=n/2)
        {
            for(j=y_start;j<n-offset;j++)
            {
                ans[x_start][j] = count;
                count ++;
            }
            for(i=x_start;i<n-offset;i++)
            {
                ans[i][j] = count;
                count ++;
            }
            for(;j>y_start;j--)
            {
                ans[i][j] = count;
                count ++;
            }
            for(;i>x_start;i--)
            {
                ans[i][j] = count;
                count ++;
            }
            x_start ++;
            y_start ++;
            offset ++;
            level ++;
        }   

        if(n%2==1)
        {
            ans[x_start][y_start] = count;
        }
        return ans;
    }
};