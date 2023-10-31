class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;
        int n = profits.size();
        for(int i=0;i<n;i++)
        {
            // pair中第一个元素应该是capital
            projects.push_back(pair(capital[i], profits[i]));
        }

        // 从小到大sort 优先按第一个元素排序
        sort(projects.begin(), projects.end());

        priority_queue<int> max_heap;
        int curr = 0;
        for(int i=0;i<k;i++)
        {
            while(curr<n&&projects[curr].first<=w)
            {
                max_heap.push(projects[curr].second);
                curr ++;
            }

            if(max_heap.size()==0)
                return w;

            int curr_profit = max_heap.top();
            max_heap.pop();
            w += curr_profit;
        }
        return w;
    }
};

// 注意sort自动排序 是按照升序排序 并且如果元素是pair 排序时优先考虑第一个元素

// space complexity for heap is O(n)