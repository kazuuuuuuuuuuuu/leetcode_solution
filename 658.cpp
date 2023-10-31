// 这道题需要k个尽量小的数 -> 用大根堆 -> 超过k后每次pop掉最大的数即可
// top k 问题

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> max_heap;
        for(int num : arr)
        {
            // the distance should be the first 
            // and the value itself should be the second
            // the priority for comparison is in this order

            // o(n log k)
            // the number of elements in the heap is k
            // so the time complexity for each heap operation is logk
            // and there are n elements in the array
            max_heap.push(pair(abs(num-x), num));
            if(max_heap.size()>k)
                max_heap.pop();
        }        

        vector<int> ans;
        while(max_heap.size()>0)
        {
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }

        // using the built-in function to sort the vector
        // o(n logn) -> since there are k elements -> o(k logk)
        sort(ans.begin(), ans.end());

        return ans;
    }
};