// 用小根堆来维护还未被预定的桌子
// 如果预定了就把他pop出去
// 重新可用的话重新加入堆
// 当然这个系统是有缺陷的 -> 加入重复的桌子等等 并没有检查和限制 -> 但可以满足题意

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
            minheap.push(i);
    }
    
    int reserve() {
        int ans = minheap.top();
        minheap.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        minheap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */