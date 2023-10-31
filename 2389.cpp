class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        // prefix sum
        // 要用binarysearch首先要排序
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            nums[i] = nums[i] + nums[i-1];
        }

        vector<int> ans;
        for(int query : queries)
        {
            // 返回上界 -》 偏移量即是答案
            int index = search(nums, query);
            ans.push_back(index);
        }

        return ans;

    }
    
    int search(vector<int> arr, int target)
    {
        int left = 0;
        int right = arr.size()-1;
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            // 此题找严格上界 把等号给left的判断
            if(arr[mid]<=target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

};