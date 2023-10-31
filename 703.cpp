// 在不断变化的集合中找最大值 -> heap
// heap中的经典实践 -> tao heaps -> 一个为maxheap 一个为minheap
// 这道题可以使用一个minheap只保存前k个元素 其他的元素直接甩掉就ok

class KthLargest {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums)
        {
            add_val(num);
        }
    }
    
    int add(int val) {
        add_val(val);
        return min_heap.top();
    }

    void add_val(int val)
    {
        // 元素必须经过 maxheap 再到 minheap
        // 以维持这两个堆的属性（minheap的所有元素大于等于maxheap的所有元素）
        max_heap.push(val);
        min_heap.push(max_heap.top());
        max_heap.pop();        


        //如果minheap元素已经足够 那么再把最小元素返还到大根堆
        if(min_heap.size()>k)
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
};
