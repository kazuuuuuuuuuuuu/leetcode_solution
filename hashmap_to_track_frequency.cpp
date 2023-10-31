int findLongestSubstring(string s, int k) {
    unordered_map<char, int> counts;
    int left = 0, ans = 0;
    
    for (int right = 0; right < s.size(); right++) {
        // 这个key还未出现的话 将自动添加
        counts[s[right]]++;
        while (counts.size() > k) {
            counts[s[left]]--;
            if (counts[s[left]] == 0) {
                counts.erase(s[left]);
            }
            left++;
        }
        
        ans = max(ans, right - left + 1);
    }
    
    return ans;
}

//  自己写一遍的练习
int findLongestSubstring(string s, int k)
{
    // first, declare a unodered_map to map a character to its frequency
    unordered_map<char, int> char_map;
    // second, using sliding window pattern
    int left = 0, right = 0, ans = 0;
    for(;right<s.size();right++)
    {
        char_map[s[right]] ++;
        while(char_map.size()>k)
        {
            char_map[s[left]] --;
            if(char_map[s[left]]==0)
                char_map.erase(s[left]);
            left ++;
        }
        ans = max(ans, right-left+1); // the formula to calculate the length of the sliding window
    }
    return ans;
}