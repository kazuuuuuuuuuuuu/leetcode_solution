class MovingAverage {
public:
    int size_;
    queue<int> queue1;
    int sum;
    MovingAverage(int size) : size_(size), sum(0) {
        
    }
    
    double next(int val) {
        queue1.push(val);
        sum += val;
        if(queue1.size()>size_)
        {
            sum -= queue1.front();
            queue1.pop();
        }
  
        return double(sum)/queue1.size();

    }
};