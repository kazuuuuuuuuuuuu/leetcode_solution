// 从所有字母中不断的选最大的 -> maxheap
//  如果已经到三次了 就一直找一个不一样的最大的
// 从另一个stack中倒回去
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) 
    {
        priority_queue<char> max_heap;
        for(char a : s)
        {
            max_heap.push(a);
        }

        string ans;
        char last;
        int time = 0;
        stack<char> char_stack;

        while(!max_heap.empty())
        {
            char curr = max_heap.top();
            max_heap.pop();
            
            if(time==0||last!=curr)
            {
                last = curr;
                time = 1;
                ans += curr;
                while(!char_stack.empty())
                {
                    char a = char_stack.top();
                    char_stack.pop();
                    max_heap.push(a);
                }
                continue;
            }

            if(last==curr&&time<repeatLimit)
            {
                last = curr;
                time ++;
                ans += curr;
                continue;
            }

            //last==curr&&time==3
            char_stack.push(curr);
        }
        return ans;
    }
};

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) 
    {
        // 计算每个字母的频率
        vector<int> freq(26);
        for(char a : s)
            freq[a-'a'] ++;

        // char在前 -> 优先比较字母大小 
        priority_queue<pair<char, int>> maxheap;
        for(int i=0;i<26;i++)
            if(freq[i]!=0)
                maxheap.push(pair('a'+i, freq[i]));

        string ans;

        while(!maxheap.empty())
        {
            char a = maxheap.top().first;
            int count = maxheap.top().second;
            maxheap.pop();
            int temp = min(repeatLimit, count);
            count = count - temp;
            while(temp)
            {
                ans += a;
                temp --;
            }

            if(maxheap.empty())
                return ans;

            // 两种情况 已经到达次数上限 和还未到达次数上限
            // 已经到达 -> 从下个元素中添加一个到ans中
            if(count!=0)
            {
                char b = maxheap.top().first;
                int b_count = maxheap.top().second;
                maxheap.pop();
                ans += b;
                b_count --;    
                maxheap.push(pair(a, count));
                if(b_count!=0)
                    maxheap.push(pair(b, b_count));      
            }
            //未到达 -> 直接处理下一个元素
        }
        return ans;
    }
};