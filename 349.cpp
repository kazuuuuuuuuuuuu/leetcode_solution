class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ans;
        unordered_set<int> set;

        for(int num : nums1)
        {
            set.insert(num);
        }

        for(int num : nums2)
        {
            if(set.find(num)!=set.end())
            {
                ans.insert(num);
            }
        }
        return vector<int> (ans.begin(), ans.end());

    }
};