class Solution {
public:
    vector<int> stoneValue;
    int n;
    vector<vector<int>> memo;
    string stoneGameIII(vector<int>& stoneValue) 
    {
        this->stoneValue = stoneValue;
        n = stoneValue.size();
        memo = vector<vector<int>>(n, vector<int> (2, INT_MAX));
        int ret = dp(0, 1);
        if(ret==0)
            return "Tie";
        if(ret>0)
            return "Alice";
        else
            return "Bob";
    }

    // return the score difference
    int dp(int i, int alice_turn)
    {
        if(i==n)
            return 0;

        if(memo[i][alice_turn]!=INT_MAX)
            return memo[i][alice_turn];

        int origin_i = i;
        if(alice_turn==1)
        {
            int sum = 0;
            int ret = INT_MIN;
            for(int j=1;j<=3;j++)
            {
                if(i<n)
                {
                    sum += stoneValue[i];
                    i ++;
                    if(sum+dp(i, 0)>ret)
                        ret = sum+dp(i, 0);             
                }
            }
            memo[origin_i][alice_turn] = ret;
            return ret;
        }
        else
        {
            int ret = INT_MAX;
            int sum = 0;
            for(int j=1;j<=3;j++)
            {
                if(i<n)
                {
                    sum -= stoneValue[i];
                    i ++;
                    if(sum+dp(i, 1)<ret)
                        ret = sum+dp(i, 1);                    
                }

            }
            memo[origin_i][alice_turn] = ret;
            return ret;
        }
    }
};