class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ran_map;
        unordered_map<char, int> mag_map;
        for(char a : ransomNote)
        {
            ran_map[a] ++;
        }
        for(char a : magazine)
        {
            mag_map[a] ++;
        }
        for(auto [key, value] : ran_map)
        {
            if(mag_map.find(key)==mag_map.end())
                return false;
            else
            {
                if(ran_map[key]>mag_map[key])
                    return false;
            }
        }
        return true;
    }
};