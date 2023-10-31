// 无法维护一个无限数量元素的容器 -> 用变量current_min代表 -> 从1开始 删掉一个就向后移动一
// 重新加入的有限元素(一定小于current_min 因为这是以前被pop掉的元素)用小根堆维护 并且加上一个set来防止重复元素的加入

class SmallestInfiniteSet {
public:
    unordered_set<int> set;
    priority_queue<int, vector<int>, greater<int>> minheap; 
    int current_min;

    SmallestInfiniteSet() {
        current_min = 1;
    }
    
    int popSmallest() {
        int ans;
        if(set.empty())
        {
            ans = current_min;
            current_min ++;
        }
        else
        {
            ans = minheap.top();
            minheap.pop();
            // the time complexity for .erase() is O(log N)
            set.erase(ans);
        }
        return ans;


    }
    
    void addBack(int num) { 
        if(num>=current_min)
            return;
        else
        {
            if(set.find(num)==set.end())
            {
                set.insert(num);
                minheap.push(num);
            }
        }
    }
};