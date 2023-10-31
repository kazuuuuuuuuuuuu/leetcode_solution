// non-decreasing subsequence

class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        n = nums.size();
        this->nums = nums;
        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(ans, curr, 0, -200);
        return ans;
    }

    // 用last_element 记录上一个元素 如果当前元素大于等于上一个元素才继续
    // 以保持单调性
    void backtrack(vector<vector<int>> &ans, vector<int> &curr, int start, int last_element)
    {
        if(curr.size()>=2)
        {
            ans.push_back(curr);
        }
        
        unordered_set<int> seen;
        for(int i=start;i<n;i++)
        {

            int num = nums[i];
            // 同层的不能有相同的 -> 用一个set记录
            if(seen.find(num)!=seen.end())
                continue;
            seen.insert(num);
            
            if(num>=last_element)
            {
                curr.push_back(num);
                backtrack(ans, curr, i+1, num);
                curr.pop_back();
            }
        }
    }
};