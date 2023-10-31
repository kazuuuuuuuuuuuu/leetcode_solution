class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> set_nums(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<=n;i++)
        {
            if(set_nums.find(i)==set_nums.end())
                return i;
        }
        return 0;
        // must return a number out of the for loop to pass compilation
    }
};

// method 2 using sorted array
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(i!=nums[i])
                return i;
        }
        return n;
    }
};

// bit manipulation by my self
// 这个无法通过因为sums 过大 当数据量小的时候是正确的
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sums = 0;
        for(int x : nums)
        {
            sums |= (1<<x);
        }
        int i = 0;
        while(sums!=0)
        {
            int bit = sums % 2;
            if(bit==0)
                return i; 
            sums /= 2;
            i ++;
        }
        return i;
    }
};

// another way using bit manipulation
// xor 记录是否出现过 出现两个就抵消 一次就会剩下 直接用在十进制上（计算机内部仍然是2进制）
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expected_xor = 0;
        int n = nums.size();
        for(int i=0;i<=n;i++)
        {
            expected_xor ^= i;
        }
        int real_xor = 0;
        for(int x : nums)
        {
            real_xor ^= x;
        }
        return real_xor ^ expected_xor;
    }
};


// 同样可以用和来实现上述的方法
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int real_sum = 0;
        for(int x : nums)
            real_sum += x;
        int n = nums.size();
        int expected_sum = 0;
        for(int i=0;i<=n;i++)
            expected_sum += i;
        // 可以用等差数列求和公式取代， 但是时间复杂度还是n 不会改变
        return expected_sum - real_sum;
    }
};