// 用binary search 找最左边的 这个到最后一个元素就都可以满足要求
// 以下这段示例代码可以找到最左边的元素

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int m = potions.size();

        // 这里spell要先换成double -> 注意类型转换的问题
        for(double spell : spells)
        {
            int index = search(potions, success / spell);

            ans.push_back(m - index);
        }

        return ans;
    }

// 返回left-most 或者插入位置
    int search(vector<int>& arr, double target) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
};