class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(ans, nums, curr);
        return ans;

    }

    // 一般来说 backtrack都是用recursion来实现
    // 每次调用一次backtrack 添加一个元素到curr中
    // 注意除了第二个参数nums的引用不是必要之外 其他参数必须要加上引用 因为每次要做修改 -> 可以节省时间空间
    void backtrack(vector<vector<int>> &ans, vector<int>& nums, vector<int>& curr)
    {
        // base case
        if(curr.size()==nums.size())
        {
            ans.push_back(curr);
            return;
        }

        for(auto num : nums)
        {
            if(find(curr.begin(), curr.end(), num)==curr.end())
            {
                curr.push_back(num);
                backtrack(ans, nums, curr);
                curr.pop_back();
            }
        }
    }
};


The time complexity of this algorithm is very slow, but the input says that 1 <= nums.length <= 6, so it is expected. 
Let n = nums.length. The initial call to backtrack (the "root" of the tree), makes n calls. 
Each of those calls makes n - 1 calls (avoiding duplicates), and each of those make n - 2, and so on. 
The exact time complexity of the algorithm is actually quite complicated, 
but we can use the logic just stated to estimate it to be around O(n⋅n!). 
There is an extra factor of n because we need to copy each permutation. 
The space complexity is O(n) for curr and the recursion call stack.