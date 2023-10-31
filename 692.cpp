// top k -> heap
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        // unordered_map to record the frequency of each word  
        unordered_map<string, int> count;
        for(string word : words)
        {
            count[word] ++;
        }  

        // put the elements in the map into the heap
        // maintain the k most frequent strings -> min_heap
        // 注意这里比较函数 先比较int 再比较string
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> min_heap;
        // minheap每次出最小 -> 字母表顺序 and freq最大（在频率前加了负号）
        for(auto [word, freq] : count)
        {
            min_heap.push(pair(-freq, word));
        }

        vector<string> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};

