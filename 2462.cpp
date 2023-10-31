// 先把候选人找出来
// 候选人加入minheap -> 比较两个matrix 1是cost 2是index
// 选出候选人 叠加工资
// 在被选出候选人的一边增加一个候选人


// 明天debug -> cost 可能为奇数或者偶数 两个退出条件不一样
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) 
    {
        int n = costs.size();
        int right = n-1;
        int left = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        while(candidates!=0)
        {
            // 针对奇数和偶数的不同退出条件
            if(right==left)
            {
                min_heap.push(pair(costs[right], right));
                right --;
                break;
            }

            if(right<left)
                break;

            min_heap.push(pair(costs[right], right));
            right --;
    
            min_heap.push(pair(costs[left], left));
            left ++;
            candidates --;
        }

        long long ans = 0;
        for(int i=0;i<k;i++)
        {
            ans += min_heap.top().first;
            int index = min_heap.top().second;
            min_heap.pop();
            if(left>right)
                continue;
               
            if(index>right)
            {
                min_heap.push(pair(costs[right], right));
                right --;
            }
            else
            {
                min_heap.push(pair(costs[left], left));
                left ++;
            }
            
            
        }
        return ans;
    }
};