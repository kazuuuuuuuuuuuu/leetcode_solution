// method 1
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        // count the number of zero
        int number_0 = 0;
        for(int x : nums)
            number_0 += (x==0);

        // push non-zero number into the answer vector
        vector<int> ans;
        for(int x : nums)
        {
            if(x!=0)
                ans.push_back(x);
        }

        // push zero in the end of the vector
        while(number_0!=0)
        {
            ans.push_back(0);
            number_0 --;
        }

        // copy the answer to the nums
        for(int i=0;i<nums.size();i++)
            nums[i] = ans[i];
        
    }
};

// two pointer 
// 将所有非零数字 从下标0开始排列好
class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int last_non_zero_number_pos = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                nums[last_non_zero_number_pos] = nums[i];
                // 这个非零数字位置的指针指向下一个位置
                last_non_zero_number_pos ++;
            }

        }
        for(int i=last_non_zero_number_pos;i<nums.size();i++)
            nums[i] = 0;
    }
};

// subtle extension
class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        
        for(int last_non_zero_number_pos=0, i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[last_non_zero_number_pos], nums[i]);
            }

        }
    }
};
