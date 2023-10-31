// 种植时间是一定要等的 长得慢的植物先种
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
    {
        int n = plantTime.size();
        vector<vector<int>> tuple;
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            temp.push_back(growTime[i]);
            temp.push_back(plantTime[i]);
            tuple.push_back(temp);
        }

        // sort 默认从小到大 转换成从大到小
        // 在这里使用自定义的比较函数
        sort(tuple.begin(), tuple.end(), costume);

        int maxtime = 0;
        int ans = 0;
        int last = 0;
        
        // 模拟一遍种植过程
        for(int i=0;i<n;i++)
        {
            int grow = tuple[i][0];
            int plant = tuple[i][1];
            ans += plant;
            last -= plant;
            last = max(last, grow);

        }
        ans += last;
        return ans;

    }
    // 这里使用&加快比较速度 才能通过
    static bool costume(vector<int> &a, vector<int> &b)
    {
        return a[0] > b[0];
    }
};