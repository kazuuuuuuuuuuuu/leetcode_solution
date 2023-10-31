// count the number of every letter

class Solution {
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char, int> freqs;
        for(char a : s)
            freqs[a] ++;
        int ans = 0;
        int odd = 0;
        for(auto [letter, freq] : freqs)
        {
            if(freq%2==0)
                ans += freq;
            else
            {
                if(freq>odd)
                {
                    odd = 1;
                    ans += freq - 1;
                }
            }
        }    
        ans += odd;
        return ans;    
    }
};