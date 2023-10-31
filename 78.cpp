class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(ans, nums, 0, curr);
        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int>& nums, int i, vector<int>& curr)
    {
        // 可以不加该判断条件 因为for循环中的循环条件已经加以限制 i永远不可能大于nums.size() 最多是等于
        // base case
        //if(i>nums.size())
            //return;
        ans.push_back(curr);

        // 尝试一个元素 -> 以该元素作为基础尝试后续元素 -> 将该元素从位置中弹出以尝试其他元素
        for(int j=i;j<nums.size();j++)
        {
            curr.push_back(nums[j]);
            // 从nums[j]元素之后的元素开始 -> index为j+1
            // an integer argument that represents the starting point for iteration at each function call
            backtrack(ans, nums, j+1, curr);
            curr.pop_back();
        }
    }
};

There are 2^n subsets, where n is the length of the input array - for each element, we can either take it or not take it. 
For the time complexity, you can think of the algorithm as a DFS on a tree with 2^n nodes. 
At each node, we make a copy of curr (where n comes from), so the time complexity is O(n⋅2^n). 
The space complexity is O(n) for curr and the recursion call stack.