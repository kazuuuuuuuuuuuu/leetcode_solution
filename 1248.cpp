// my method is the same as the standard method
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        unordered_map<int ,int> odd_num_amount;
        odd_num_amount[0] = 1;
        int ans = 0;
        int curr = 0;
        for(int x : nums)
        {
            if(x%2==1)
                curr ++;
            if(odd_num_amount.find(curr-k)!=odd_num_amount.end())
                ans += odd_num_amount[curr-k];
            odd_num_amount[curr] ++;
        }
        return ans;

    }
};

// the answer from the book
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        counts[0] = 1;
        int ans = 0, curr = 0;
        
        for (int num: nums) {
            curr += num % 2;
            ans += counts[curr - k];
            counts[curr] += 1;
        }
        
        return ans;
    }
};