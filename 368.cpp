// first thing first -> srot ->
// 这样以来如果后一个可以整除前一个 那么也可以整除前一个可以整除的
// 具有传递性
// 截至每个序号为止 都有一个最大长度的subset的length 之后的序号在这个基础上继续更新
// prev 数组记录每个元素的上一个元素

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();
        if(n<=1)
            return vector<int> (nums.begin(), nums.end());
        sort(nums.begin(), nums.end());

        vector<int> length(n, 1);
        vector<int> prev(n, -1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] % nums[j] == 0)
                {
                    // 如果比当前的要大 那么进行更新
                    if(length[j] + 1 > length[i])
                    {
                        length[i] = length[j] + 1;
                        prev[i] = j;                  
                    }

                }
            }
        }

        int max_index = 0;
        for(int i=0;i<n;i++)
        {
            if(length[i]>length[max_index])
                max_index = i;
        }
        vector<int> ans;
        ans.push_back(nums[max_index]);
        while(prev[max_index]!=-1)
        {
            max_index = prev[max_index];
            ans.push_back(nums[max_index]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};