// my method works, but it exceeds the time limitation
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long result = 0;
        for(int k=1;k<=nums.size();k++)
        {
            result += sub_with_length_k(nums, k);
        }
        return result;
    }

    long sub_with_length_k(vector<int>& nums, int k)
    {
        deque<int> incre;
        deque<int> decre;
        long result = 0;
        int right = 0;
        int left = 0;

        for(;right<nums.size();right++)
        {
            // monotonically increasing deque
            // record the min value
            if(incre.empty())
                incre.push_back(right);
            else
            {
                while(!incre.empty()&&nums[incre.back()]>=nums[right])
                {
                    incre.pop_back();
                }
                incre.push_back(right);
            }

            // monotonically decresing deque
            // record the max value
            if(decre.empty())
                decre.push_back(right);
            else
            {
                while(!decre.empty()&&nums[decre.back()]<=nums[right])
                {
                    decre.pop_back();
                }
                decre.push_back(right);
            }

            // check the length of the subarray
            if(right-left+1>k)
            {
                if(incre.front()==left)
                    incre.pop_front();
                if(decre.front()==left)
                    decre.pop_front();
                left ++;
            }
            if(right-left+1==k)
                result += nums[decre.front()] - nums[incre.front()];
        }
        return result;
    }
};


// method 2

// assume there are k subarrays in total
// 1
// answer =  (max - min) of k subarrays
// = sum of every max(in number of k) - sum of every min(in number of k)

// 2 (the method to evaluate the sum of every min is the same )
// sum of every max = each value * the number of subarrays using this value as the minimum value

// 3 evaluate the time of each value being the min 
// using a monotonically increasing stack 
// the value of the current element > the value of the top element
// the value of the current element <= the value of the element popped

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        int n = nums.size();
        long long answer = 0;
        stack<int> incre;
        stack<int> decre;
        
        // sum of all the maximum -> need a decreasing stack
        for(int i = 0;i<=n;i++)
        {
            // i == n || nums[decre.top()]<=nums[i] 
            // i is the location for the popped one not being maximum 
            while(!decre.empty()&&(i==n||nums[decre.top()]<=nums[i]))
            {
                int mid = decre.top();
                decre.pop();
                int left = decre.empty()? -1:decre.top();
                answer += (long long)nums[mid] * (i-mid) * (mid-left);
            }
            decre.push(i);
            // sum of all the minimum -> need an increasing stack
            while(!incre.empty()&&(i==n||nums[incre.top()]>=nums[i]))
            {
                int mid = incre.top();
                incre.pop();
                int left = incre.empty()? -1:incre.top();
                answer -= (long long)nums[mid] * (mid-left) * (i-mid);
            }
            incre.push(i);
        }
        return answer;
    }
};

// review
// 思路总结
// 1 由算每个subarray的max-min的和 -> 算每个subarray的max和 - 每个subarray的min的和
// 2.1 算每个subarray的max的和 -> 每个值 * 他作为max的subarray的个数
// 3 他作为max的subarray的个数 -> 可能的起点数 * 可能的终点数
// 4.1 可能的起点数 -> 该数字的位置 - 他不在作为最大值的失效位置
// 4.2 可能的终点数 -> 他不在作为最大值的失效位置 - 该数字的位置
// 2.2 算每个subarray的min的和 重复之前的过程

long long subArrayRanges(vector<int>& nums)
{
    int n = nums.size();
    long long answer = 0;
    stack<int> incre;
    stack<int> decre;
    // n作为所有栈中元素的失效位置
    for(int i = 0;i<=n;i++)
    {
        // find maixmum
        while(!decre.empty()&&(i==n||nums[decre.top()]<=nums[i]))
        {
            int mid = decre.top();
            decre.pop();
            int left = decre.empty()? -1:decre.top();
            answer += (long long)nums[mid] * (mid-left) * (i-mid);
        }
        decre.push(i);

        // find minimum
        while(!incre.empty()&&(i==n||nums[incre.top()]>=nums[i]))
        {
            int mid = incre.top();
            incre.pop();
            int left = incre.empty()? -1:incre.top();
            answer -=  (long long)nums[mid] * (mid-left) * (i-mid);
        }
        incre.push(i);
    }
    return answer;
} 