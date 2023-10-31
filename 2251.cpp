// 该方法正确 但是需要的桶实在是太大了
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) 
    {
        // 桶排序
        vector<vector<int>> buckets(101);
        for(auto &flower : flowers)
        {
            int begin = flower[0];
            int end = flower[1];
            buckets[begin].push_back(end);
        }

        // sort the inner vector
        for(auto &bucket : buckets)
            sort(bucket.begin(), bucket.end());

        vector<int> ans;
        for(auto &person : people)
        {
            int num = 0;
            for(int k=0;k<=person;k++)
            {
                num += buckets[k].end() - lower_bound(buckets[k].begin(), buckets[k].end(), person);
            }
            ans.push_back(num);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) 
    {
        // 基于红黑树实现 key有序
        map<int, int> mp;

        // 记录 开花 和 凋谢的时间 -> key是天
        for(auto &flower : flowers)
        {
            int bloom = flower[0];
            // 花期最后一天的下一天是凋谢
            int die = flower[1] + 1;
            mp[bloom] ++;
            mp[die] --;
        }

        // 记录有变化的天的花开的数量
        // 每一天开始叠加直到当前遍历的这天
        int sum = 0;
        for(auto &day : mp)
        {
            sum += day.second;
            mp[day.first] = sum;
        }

        vector<int> ans;
        for(auto &person : people)
        {
            // 基于key来查找
            //auto it = lower_bound(mp.begin(), mp.end(), person); 
            // 不可以这样使用lower_bound 这种要求该容器是可以随机存取的容器
            auto it = mp.lower_bound(person);
            // 正好查找到当天
            if(it!=mp.end())
            {   // 注意迭代器是指针 不能用成员运算符引用成员
                if(it->first==person)
                {
                    ans.push_back(it->second);
                    continue;                  
                }
                if(it==mp.begin())
                {
                    ans.push_back(0);
                    continue;
                }
                it --;
                ans.push_back(it->second);
            }
            else
            {
                it --;
                ans.push_back(it->second);
            }
            
        }
        return ans;
    }
};