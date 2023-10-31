bool fun(vector<int> &nums, int target)
{
	int i = 0;
	int j = nums.size() - 1;
	while(i<j)
	{
		int curr = nums[i] + nums[j];
		if(curr==target)
			return true;
		if(cur<target)
			i ++;
		else
			j --;
	}
	return false;
}