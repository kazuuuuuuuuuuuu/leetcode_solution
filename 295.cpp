// 找median(中间值) -> two heaps
// 所有元素分为两个组 -> 大的一组小的一组 -> 大的组中最小的 和 小的组中最大的就是中间值
// 创建两个组的过程
// 先添加元素到 小组 再从中选最大的添加到大组
// （如果大组中元素个数多余小组） 将大组中的最小值 返回到小组中

class MedianFinder {
public:
    // 定义一个大的组和小的组
    // 大根堆 -> top()元素为最大值
    priority_queue<int> max_heap;
    // 小根堆 -> top()元素为最小值
    // 注意小根堆的定义方法
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        if(min_heap.size()>max_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() 
    {
        if(max_heap.size()>min_heap.size())
            return max_heap.top();
        else if(max_heap.size()==min_heap.size())
            return (max_heap.top() + min_heap.top()) / 2.0;
        else 
            return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    
    MedianFinder() {}
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        
        return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};