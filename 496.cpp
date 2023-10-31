// make use of pre_processing, establish a mapping
// find the next greater element of each element in nums2, store the result in a map
// iterate over the nums1, find the corresponding next greater element from map and append it to the answer vector

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> stack;
        for(int x : nums2)
        {
            while(!stack.empty()&&stack.top()<x)
            {
                next_greater[stack.top()] = x;
                stack.pop();
            }
            stack.push(x);
        }

        while(!stack.empty())
        {
            next_greater[stack.top()] = -1;
            stack.pop();
        }

        vector<int> ans;
        for(int x : nums1)
        {
                ans.push_back(next_greater[x]);
        }
        return ans;
    }
};