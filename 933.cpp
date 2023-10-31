class RecentCounter {
public:
    queue<int> queue;
    RecentCounter() {}
    
    int ping(int t) {
        queue.push(t);
        while(!queue.empty()&&queue.front()<t-3000)
        {
            queue.pop();
        }
        return queue.size();
    }
};
