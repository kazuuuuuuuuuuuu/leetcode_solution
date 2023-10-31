class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) 
    {
        sort(price.begin(), price.end());
        int left = 1;
        int right = 1000000000;
        // possible impossible
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(check(price, k, mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }

    // 最小值 -> 其他值要大于等于这个值
    // 排序后每个元素之间的值就是最小值的可选范围 -> 排序后的之间的差值比较小
    bool check(vector<int>& price, int k, int tastiness)
    {
        int num = 1;
        int last = price[0];
        for(int p : price)
        {
            if((p-last)>=tastiness)
            {
                num ++;
                last = p;
                if(num==k)
                    return true;
            }    
        }
        return false;
    }
};