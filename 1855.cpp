class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) 
    {
        // solution space (distance)
        // possible impossible
        int left = 0;
        int right = max(nums1.size(), nums2.size());
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(check(nums1, nums2, mid))
                left = mid + 1;
            else
                right = mid - 1;
        }    
        if(right==-1)
            return 0;
        else
            return right;
    }

    // 查找是否存在这样一个distance
    bool check(vector<int>& nums1, vector<int>& nums2, int distance)
    {
        int i = 0;
        int n = nums1.size();
        int m = nums2.size();
        for(;i<n;i++)
        {
            //  直接从distance之后开始查找， 大于这个distance也算满足条件
            for(int j=i+distance;j<m;j++)
            {
                if(nums1[i] <= nums2[j])
                    return true;
                // 如果不满足条件的话 j之后的数字只会更小 没有考虑的必要直接break
                else 
                    break;
            }
        }    
        return false;
    }
};