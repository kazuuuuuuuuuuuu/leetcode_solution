class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) 
    {
        sort(clips.begin(), clips.end());
        int n = clips.size();
        // traverse all inputs to reconstruct the clip
        int curr = 0;
        int i = 0;
        int ans = 0;

        while(curr<time&&i<n)
        {
            int temp = -1;
            for(;i<n;i++)
            {
                int start = clips[i][0];
                int end = clips[i][1];
                if(start<=curr)
                {
                    temp = max(temp, end);
                }
                else
                    // 在这里break将跳过i++
                    break;
            }
            if(temp==-1)
            {
                return -1;
            }
            else
            {
                ans ++;
                curr = temp;
            }
        }
        if(curr>=time)
            return ans;
        else 
            return -1;
    }
};