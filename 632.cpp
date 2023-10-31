class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        vector<int> answer;
        int answer_length;    
        int n = nums.size(); 
        int max_value = nums[0][0];
        pair<int, int> max_element;

        // 下标数组 记录当前轮次中 每个list中 被考虑的元素的下标
        vector<int> pointers(n, 0);
        vector<int> length_list(n, 0);

        // min_heap 存储元素值 和该元素所在的列表的下标
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for(int i=0;i<n;i++)
        {
            int curr_value = nums[i][0];
            
            if(curr_value>max_value)
            {
                max_value = curr_value;
                max_element = pair(curr_value, i);
            }

            min_heap.push(pair(curr_value, i));

            length_list[i] = nums[i].size();
        }

        while(1)
        {
            // 计算answer
            pair<int, int> min_element = min_heap.top();
            min_heap.pop();

            int min_value = min_element.first;
            int min_index = min_element.second;

            int curr_length = max_value - min_value;
            
            if(answer.size()==0)
            {
                // 初始化
                answer.push_back(min_value);
                answer.push_back(max_value);
                answer_length = max_value - min_value;
            }    

            if(curr_length<answer_length)
            {
                answer_length = curr_length;
                answer.clear();
                answer.push_back(min_value);
                answer.push_back(max_value);
            }    

            // 更新 最小值所在的列表的pointer
            pointers[min_index] ++;

            // 列表耗尽 退出
            if(pointers[min_index]>=length_list[min_index])
                break;

            int new_value = nums[min_index][pointers[min_index]];
            int new_index = min_index;
            // 更新存储最小值的min_heap
            min_heap.push(pair(new_value, new_index));

            // 更新最大值
            if(new_value>max_value)
            {
                max_value = new_value;
                max_element = pair(new_value, new_index);
            }
        }
        return answer;
    }
};


// 每个列表一个指针（下标） 指向此列表当前被考虑元素
// 记录每一个列表的长度 当任何一个列表的指针越界时停止迭代
// 记录一个 全局range 作为答案 包含开始值 结束值 以及长度
// 记录上一个range的开始值和结束值
// 计算当前的range值 1首先和上一次的max值比较 2用min_heap维护每次range的最小值