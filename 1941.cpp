// method 1  by myself
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> char_frequency;
        for(char a : s)
            char_frequency[a] ++;
        int last = -1;
        for(auto pair : char_frequency)
        {
            if(last==-1)
                last = pair.second;
            else
            {
                if(last!=pair.second)
                    return false;
            }
        }
        return true;
    }
};

// mehthod 2 to check if the frequencies are all the same
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> char_frequency;
        for(char a : s)
            char_frequency[a] ++;
        // if all the frequencies are the same, and the set removes all the duplicates
        // the size of set will be 1
        unordered_set<int> count;
        for(auto pair : char_frequency)
        {
            count.insert(pair.second);
        }
        return (count.size())==1;
    }
};