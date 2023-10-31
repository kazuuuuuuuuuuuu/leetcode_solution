class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) 
    {
        // solution space
        // possible impossible
        int left = 1;
        int right = 0;
        for(int s : sweetness)
            right += s;
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(check(sweetness, mid, k))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }

    bool check(vector<int> &sweetness, int x, int k)
    {
        int j = 0;
        int n = sweetness.size();
        for(int i=0;i<k+1;i++)
        {
            int sum = 0;
            while(sum<x)
            {
                if(j==n)
                    return false;
                sum += sweetness[j];
                j ++;
            }
        }
        return true;
    }
};