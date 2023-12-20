class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) 
    {
        if(nums.size()<=2)
            return nums.size();

        int ans = 0;
        int n = nums.size();
        vector<unordered_map<int, int>> map = vector<unordered_map<int, int>> (n, unordered_map<int, int> {});
        for(int i=1;i<n;i++)
        {
            // check the element before
            for(int j=0;j<i;j++)
            {
                int diff = nums[i] - nums[j];
                map[i][diff] = 1;
                if(map[j].find(diff)!=map[j].end())
                    map[i][diff] += map[j][diff];
                else
                    map[i][diff] ++;
                
                ans = max(ans, map[i][diff]);
            }
        }
        return ans;
    }
};

// 这道题一个状态所要考虑的状态变量为i 和diff 但是diff太多了
// 用dp的递归方法会超时
// 用迭代的方法简单一点