class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // hash_map 用来计算频率
        unordered_map<int, int> freq;
        for(int num : arr)
        {
            freq[num] ++;
        }

        vector<int> ordered;
        for(auto [key, val] : freq)
        {
            ordered.push_back(val);
        }

        // sort 默认是递增 现在我们用递减
        sort(ordered.begin(), ordered.end(), greater<int>());

        while(k>0)
        {
            int value = ordered.back();
            if(value<=k)
            {
                k -= value;
                ordered.pop_back();
            }
            else
                break;
        }
        return ordered.size();
    }
};

// sort的时间复杂度 O(n log n)
// hash map的空间复杂度是 O(n)