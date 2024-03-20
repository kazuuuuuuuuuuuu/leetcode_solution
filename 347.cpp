// 用小根来maintain前k个元素 -> 当一个元素被添加进heap 此时heap中的元素数量多于k -> pop
// 堆中的元素可以是pair -> pair中位置0的元素用于比较 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 用到小根堆 -> 大根堆+元素乘以-1 or 直接用小根堆
        unordered_map<int, int> frequency;
        for(int num: nums)
        {
            frequency[num] ++;
        }

        priority_queue<pair<int ,int>> max_heap;
        for(auto [val, freq] : frequency)
        {
            // the freq is first for comprison
            max_heap.push(pair(-freq, val));
            if(max_heap.size()>k)
                max_heap.pop();
        }

        vector<int> ans;
        while(max_heap.size()>0)
        {
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return ans;
    }
};


class Solution {
public:
    // 仿函数
    struct compare
    {
        // 重定义调用运算符
        bool operator()(vector<int> &a, vector<int>&b)
        {
            return a[1] > b[1];
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> map;
        for(int num : nums)
        {
            map[num] ++;
        }

        priority_queue<vector<int>, vector<vector<int>>, compare> min_heap;
        for(auto[key, value] : map)
        {
            vector<int> next = {key, value};
            min_heap.push(next);
            if(min_heap.size()>k)
                min_heap.pop();
        }

        vector<int> ans(k);
        for(int i=k-1;i>=0;i--)
        {
            ans[i] = min_heap.top()[0];
            min_heap.pop();
        }
        return ans;
    }
};