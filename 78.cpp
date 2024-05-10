

//There are 2^n subsets, where n is the length of the input array - for each element, we can either take it or not take it. 
//For the time complexity, you can think of the algorithm as a DFS on a tree with 2^n nodes. 
//The space complexity is O(n) for curr and the recursion call stack.


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> nums;
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        this->nums = nums;
        backtrack(0);
        return ans;
    }

    void backtrack(int startindex)
    {
        ans.push_back(path);
        if(startindex==nums.size()) return; // 可以不加该判断条件 因为for循环中的循环条件已经加以限制 i永远不可能大于nums.size() 最多是等于
        for(int i=startindex;i<nums.size();i++) // 尝试一个元素 -> 将该元素从位置中弹出以尝试其他元素
        {
            path.push_back(nums[i]);
            backtrack(i+1); // 之前的元素不再考虑
            path.pop_back();
        }
    }
};