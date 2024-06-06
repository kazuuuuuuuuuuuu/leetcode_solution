class Solution {
public:
    // 数据第二个维度不是连续整数 不能用vector用map
    vector<unordered_map<int, int>> memo;
    vector<int> nums;
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        memo = vector<unordered_map<int, int>>(nums.size(), unordered_map<int, int> ());
        this->nums = nums;
        int n = nums.size();
        return dp(n-1, target);

    }

    // dp数组含义 -> 考虑nums数组中第i个位置 装满curr_weight有多少种方法 
    int dp(int i, int curr_weight)
    {
        // base case 考虑等0号元素
        if(i==0)
        {
            // 和目标值相同或相反
            if(curr_weight==nums[0]||curr_weight==(-nums[0]))
            {
                // 0的话返回两种情况 既可以是+也可以是-
                if(curr_weight==0)
                    return 2;
                return 1;
            }
            else
                return 0;
        }

        if(memo[i].find(curr_weight)!=memo[i].end())
            return memo[i][curr_weight];

        int ans = 0;
        int num = nums[i];
        // 当前位置用减法，上一个状态是 curr_weight+num
        ans += dp(i-1, curr_weight+num);
        // 当前位置用加法，上一个状态是 curr_weight-num
        ans += dp(i-1, curr_weight-num);
        memo[i][curr_weight] = ans;
        return ans;
    }
};


// 另外一种frame问题的方式
class Solution {
public:
    // 数据第二个维度不是连续整数 不能用vector用map
    vector<unordered_map<int, int>> memo;
    vector<int> nums;
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        memo = vector<unordered_map<int, int>>(nums.size(), unordered_map<int, int> ());
        this->nums = nums;
        int n = nums.size();
        int sum = 0;
        for(int num : nums)
        {
            sum += num;
        }
        if((sum+target)%2!=0) return 0;
        // right + left = sum, right - left = target -> 2 * right = sum + target
        int right = (sum+target)/2;
        // 凑right一共有多少种方法
        return dp(n-1, right);
    }

    // dp数组含义 -> 考虑nums数组中第i个位置 装满curr_weight有多少种方法 
    int dp(int i, int curr_weight)
    {
        // 所有元素全部被考虑了
        if(i<0)
        {

            if(curr_weight==0)
            {
                return 1;
            }
            else
                return 0;
        }

        if(memo[i].find(curr_weight)!=memo[i].end())
            return memo[i][curr_weight];

        int ans = 0;
        int num = nums[i];
        // 用当前i的元素有多少方式
        if(curr_weight>=num)
        {
            ans += dp(i-1, curr_weight-num);
        }
        // 不用当前i的元素有多少方式
        ans += dp(i-1, curr_weight);
        return ans;
    }
};