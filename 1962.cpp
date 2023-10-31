// 执行k次操作后 的最小值  ->  每次都把最大值减半
// 这里减半后需要做向上取整 -> round x up!

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        priority_queue<int> maxheap(piles.begin(), piles.end());
        int total = 0;
        for(int num : piles)
            total += num;
        for(int i=0;i<k;i++)
        {
            int x = maxheap.top();
            maxheap.pop();
            // round x up
            int y = (x + 1) / 2;
            total -= (x - y);
            maxheap.push(y);
        }
        return total;
    }
};

// converting a vector to heap can take o(n) time
// plus the k iteration of heap operations which leads to o(k log n）
// space complexity is o(n)