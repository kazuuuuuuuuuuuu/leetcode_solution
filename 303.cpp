class NumArray {
private:
    vector<int> storage;
public:
    NumArray(vector<int>& nums) 
    {
        for(int x : nums)
            storage.push_back(x);
    }
    
    int sumRange(int left, int right) 
    {
        int ans = 0;
        int n = storage.size();
        vector<int> sums(n);
        sums[0] = storage[0];
        for(int i=1;i<n;i++)
            sums[i] = sums[i-1] + storage[i];
        ans = sums[right] - sums[left] + storage[left];
        return ans;   
    }
};