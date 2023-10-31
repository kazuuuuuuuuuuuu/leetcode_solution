class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        priority_queue<pair<int, int>> max_heap;

        for(vector<int> &boxType : boxTypes)
        {
            int num_box = boxType[0];
            int num_unit = boxType[1];

            max_heap.push(pair(num_unit, num_box));
        } 

        int ans = 0;
        while(truckSize!=0&&max_heap.size()!=0)
        {
            pair<int, int> box = max_heap.top();
            max_heap.pop();
            int num_box = box.second;
            int num_unit = box.first;

            if(truckSize>=num_box)
            {
                truckSize -= num_box;
                ans += num_box * num_unit;
            }
            else
            {
                ans += truckSize * num_unit;
                break;
            }
        }
        return ans;
    }
};


// 可以用sort解决这个问题 注意这里有一个自定义的比较函数 用于sort第三个参数 即函数指针
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        sort(boxTypes.begin(), boxTypes.end(), customized_compare);
        int ans = 0;
        for(auto boxType : boxTypes)
        {
            int num_box = boxType[0];
            int num_unit = boxType[1];
            if(truckSize>=num_box)
            {
                ans += num_box * num_unit;
                truckSize -= num_box;
            }
            else
            {
                ans += truckSize * num_unit;
                break;
            }
        }
        return ans;
    }

    // sort 默认是升序排列 可以修改变为降序
    static bool customized_compare(vector<int> p1, vector<int> p2)
    {
        return p1[1]>p2[1];
    }
};
