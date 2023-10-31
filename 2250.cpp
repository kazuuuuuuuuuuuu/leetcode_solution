class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) 
    {
        // 建立一个足够大的桶
        // 下标为l 每个元素本身是由相同l的h们组成的数组
        // x 本身是下标所以是排好序的 -> 从0到100
        // ！！！！！！！！！！！！
        // 这道题用h作为下标才不会超时 l做下标会超时
        vector<vector<int>> bucket(101);
        for(auto &rectangle : rectangles)
        {
            int l = rectangle[0];
            int h = rectangle[1];
            bucket[l].push_back(h);
        }
        // 对h数组进行排序
        for(auto &array_h : bucket)
        {
            sort(array_h.begin(), array_h.end());
        }

        vector<int> ans;
        for(auto &point : points)
        {
            int x = point[0];
            int y = point[1];
            int num = 0;
            for(int k=x;k<=100;k++)
            {
                // 桶内从指定k元素开始
                // 对每一元素本身（都是一个vector）进行binarysearch
                // 返回第一个大于等于y的元素的迭代器 -> 使用内置的二分查找
                num += bucket[k].end() - lower_bound(bucket[k].begin(), bucket[k].end(), y);
            }
            ans.push_back(num);
        }
        return ans;
    }
};

