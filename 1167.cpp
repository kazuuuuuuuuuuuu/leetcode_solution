// 每次选出最小的两个值 相加 然后重新放入堆中 
// 直到堆中只有一个元素停止

class Solution {
public:
    int connectSticks(vector<int>& sticks) 
    {
        priority_queue<int, vector<int>, greater<int>> min_heap(sticks.begin(), sticks.end());
        int cost = 0;
        while(min_heap.size()>1)
        {
            int x = min_heap.top();
            min_heap.pop();
            int y = min_heap.top();
            min_heap.pop();
            int combine = x + y;
            cost += combine;
            min_heap.push(combine);
        }

        return cost;
    }
};