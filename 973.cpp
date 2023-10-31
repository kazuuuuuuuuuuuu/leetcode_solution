// 这道题我用每一组坐标在输入中的下标作为它的唯一标识
// topk -> 求最近的 -> 每次弹出最大的
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int, double> map;
        int n = points.size();
        for(int i=0;i<n;i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            double distance = sqrt(x*x + y*y);
            map[i] = distance;
        }

        priority_queue<pair<double,int>> max_heap;
        for(auto [index, dis] : map)
        {
            max_heap.push(pair(dis, index));
            if(max_heap.size()>k)
                max_heap.pop();
        }
        vector<vector<int>> ans;
        while(!max_heap.empty())
        {
            int index = max_heap.top().second;
            ans.push_back(points[index]);
            max_heap.pop(); 
        }

        return ans;
    }
};

