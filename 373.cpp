// every inddex shifts by one after one selection
// At each step
// we chose the minimum sum pair from the remaining leftover pairs and the next two new pairs
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n =nums2.size();
        vector<vector<int>> ans;
        // 用seen set来避免重复访问的情况
        set<pair<int, int>> seen;
        // minheap -> 第一个元素用来排序 第二个元素(pair) -> 用作存储该点的坐标
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> min_heap;
        
        int sum = nums1[0] + nums2[0];
        seen.insert(pair(0, 0));
        min_heap.push(pair(sum, pair(0, 0)));

        while(k!=0&&!min_heap.empty())
        {
            auto top = min_heap.top();
            min_heap.pop();
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});
            // 每次从堆中删除一个元素 -> 随后添加两个元素 -> i,j+1 和 i+1,j
            // 如果下标有效(未超界) 并且并未访问过 -> 重新添加到堆当中
            if(i+1<m&&seen.find(pair(i+1, j))==seen.end())
            {
                seen.insert(pair(i+1, j));
                min_heap.push(pair(nums1[i+1]+nums2[j], pair(i+1, j)));
            }
            if(j+1<n&&seen.find(pair(i, j+1))==seen.end())
            {
                seen.insert(pair(i, j+1));
                min_heap.push(pair(nums1[i]+nums2[j+1], pair(i, j+1)));
            }
            k--;
        }
        return ans;
    }
};


