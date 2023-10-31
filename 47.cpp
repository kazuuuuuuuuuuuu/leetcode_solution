// permutation -> backtrack
// P(N, N) 的全排列
class Solution {
public:
    vector<bool> seen;

    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        seen = vector<bool> (nums.size(), false);
        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(ans, curr, nums);
        return ans;

    }

    void backtrack(vector<vector<int>> &ans, vector<int> &curr, vector<int>& nums)
    {
        if(curr.size()==nums.size())
        {
            // 可能会有重复 去重
            if(find(ans.begin(), ans.end(), curr)==ans.end())
            {
                ans.push_back(curr);
                return;  
            }

        }

        for(int i=0;i<nums.size();i++)
        {
            if(!seen[i])
            {
                // backtrack two states variable, one for seen set, one for curr vector
                seen[i] = true;
                curr.push_back(nums[i]);
                backtrack(ans, curr, nums);
                seen[i] = false;
                curr.pop_back();
            }
        }
    }
};

// 该方法效率更高
// 用元素种类去做每个位置的可选项 可以减少重复
class Solution {
public:
    unordered_map<int, int> freqs;
    int n;

    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        n = nums.size();
        for(int &num : nums)
        {
            freqs[num] ++;
        }
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, curr);
        return ans;


    }

    void backtrack(vector<vector<int>> &ans, vector<int> &curr)
    {
        if(curr.size()==n)
        {
            ans.push_back(curr);
            return;  
        }

        for(auto &[num, freq] : freqs)
        {
            if(freq!=0)
            {
                // backtrack two states variable
                freq --;
                curr.push_back(num);
                backtrack(ans, curr);
                freq ++;
                curr.pop_back();
            }
        }
    }
};