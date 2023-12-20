class Solution {
public:
    int k;
    int n;
    long long result_pow = pow(10, 9) + 7;
    vector<unordered_map<int, long long>> memo;
    int numRollsToTarget(int n, int k, int target) 
    {
        this->k = k;
        this->n = n;
        memo = vector<unordered_map<int, long long>> (n, unordered_map<int, long long> {});
        return dp(0, target);
    }

    long long dp(int i, int target)
    {
        if(i==n)
        {
            if(target==0)
                return 1;
            else
                return 0;
        }

        if(memo[i].find(target)!=memo[i].end())
            return memo[i][target];

        long long ret = 0;
        for(int num=1;num<=k;num++)
        {
            if(num<=target)
            {
                ret += dp(i+1, target-num);
            }
            else
                break;
        }
        memo[i][target] = ret % result_pow;
        return memo[i][target];
    }
};