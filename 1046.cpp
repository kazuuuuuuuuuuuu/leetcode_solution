class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(stones.begin(), stones.end());
        while(heap.size()>1)
        {
            int first = heap.top();
            heap.pop();
            int second = heap.top();
            heap.pop();
            int diff = first - second;
            if(diff!=0)
                heap.push(diff);
        }      

        return heap.size()==0 ? 0 : heap.top();
    }
};