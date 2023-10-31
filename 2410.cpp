class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int n = players.size();
        int m = trainers.size();

        int i = 0;
        int j = 0;
        int ans = 0;
        while(i<n&&j<m)
        {
            int curr = players[i];
            while(j<m&&trainers[j]<curr)
            {
                j ++;
            }
            if(j<m)
            {
                ans ++;
                i ++;
                j ++;
            }
            else 
                break;
        }
        return ans;
    }
};