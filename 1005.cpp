class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        int ans = 0;
        sort(nums.begin(), nums.end(), compare);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0&&k>0)
            {
                k --;
                nums[i] *= -1;
            }

            if(i==(nums.size()-1)&&k%2==1)
            {
                nums[nums.size()-1] *= -1;
            }

            ans += nums[i];
        }
        return ans;
    }

    // static -> 不使用对象也可以调用的类方法 
    // 最后就按照 > 的顺序 一直排列下去
    static bool compare(int &a, int &b)
    {
        return abs(a)>abs(b);
    }
};

