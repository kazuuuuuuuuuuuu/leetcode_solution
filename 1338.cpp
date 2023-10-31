class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        int size = arr.size();
        int half = size / 2;
        unordered_map<int, int> freqs;
        for(int num : arr)
        {
            freqs[num] ++;
        }  
        priority_queue<int> max_heap;
        for(auto [num, freq] : freqs)
        {
            max_heap.push(freq);
        }

        int ans = 0;
        while(size>half)
        {
            int top_freq = max_heap.top();
            max_heap.pop();
            size -= top_freq;
            ans ++;
        }
        return ans;
    }
};