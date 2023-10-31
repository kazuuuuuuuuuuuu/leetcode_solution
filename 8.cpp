int fun(vector<int> &nums, int k)
{
	int curr = 0;
	for(int i=0;i<k;i++)
	{
		curr += nums[i];
	}
	int ans = curr;
	for(int i=k;i<nums.size();i++)
	{
		curr += nums[i];
		curr -= nums[i-k];
		ans = max(ans, curr);
	}
	return ans;
}