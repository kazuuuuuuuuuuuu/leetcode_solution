//sliding window with set to record the elements in the window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> char_set;
        int left = 0, right = 0;
        int max = 0;
        for(;right<s.size();right++)
        {
            char add = s[right];
            if(char_set.find(add)!=char_set.end())
            {
                while(s[left]!=add)
                {
                    char_set.erase(s[left]);
                    left ++;
                }
                left ++;
            }
            else
            {
                char_set.insert(add);
            }
            max = max>(right-left+1)?max:(right-left+1);
        }
        return max;
    }
};

//using map to record the duplicate char with its index
 int lengthOfLongestSubstring(string s)
 {
    unordered_map<char, int> char_map;
    int left = 0, right = 0;
    int max = 0;
    for(;right<s.size();right++)
    {
        char add = s[right];
        if(char_map.find(add)!=char_map.end()&&char_map[add]>=left)
        {
            left = char_map[add] + 1;
        }
        char_map[add] = right;
        max = max>(right-left+1)?max:(right-left+1);
    }
    return max;
 }