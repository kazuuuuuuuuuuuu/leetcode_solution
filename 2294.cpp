// subsequences -> a group of elements from the array that keep their order
// the elements dont have to be adjacent

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
    	sort(nums.begin(), nums.end());

	  	int x = nums[0];
	  	int ans = 1;
	  	for(int num : nums)
	  	{
	  		if(num<=x+k)
	  			continue;
	  		x = num;
	  		ans ++;
	  	}      
	  	return ans;
    }
};

// sort()的空间复杂度为O(log n)
// 时间复杂度为O(n log n)