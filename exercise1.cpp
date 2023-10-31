
vector<int> findNumbers(vector<int>& nums) 
{
	vector<int> ans;
	unordered_set<int> num_set;
	for(int num : nums)
		num_set.insert(num);
	for(int num : num_set)
		if(num_set.find(num-1)==num_set.end()&&num_set.find(num+1)==num_set.end())
			ans.push_back(num);
	return ans;
}

//unordered_set 这里说的unordered是 unordered_set中的value 不会根据大小被排序 而set由树实现 元素是有序的
//
vector<int> findNumbers(vector<int>& nums) {
    vector<int> ans;
    unordered_set<int> numsSet(nums.begin(), nums.end()); // set的另一种初始化方式
    
    for (int num: nums) {
        if (numsSet.find(num + 1) == numsSet.end() && numsSet.find(num - 1) == numsSet.end()) {
            ans.push_back(num);
        }
    }
    
    return ans;
}