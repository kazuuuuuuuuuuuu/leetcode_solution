// 贪婪算法 每次 移动小的那条边即可
// 大的那条边保持不动

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        int curr = 0;

        while(left<right)
        {
            curr = min(height[left], height[right]) * (right - left);
            
            if(curr>ans)
                ans = curr;

            // move pointer
            if(height[left]<height[right])
            {
                left ++;
            }
            else
            {
                right --;
            }
        }    
        return ans;
    }
};