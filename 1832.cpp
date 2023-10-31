class Solution {
public:
    bool checkIfPangram(string sentence) {
        // We iterate over 'sentence' for 26 times, one for each letter 'currChar'.
        for (int i = 0; i < 26; ++i) {
            char currChar = 'a' + i;
            
            // If 'sentence' doesn't contain currChar, it is not a pangram.
            if (sentence.find(currChar) == string::npos)
                return false;
        }
        
        // If we manage to find all 26 letters, it is a pangram.
        return true;
    }
};

class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        unordered_set<char> char_set;
        for(char a : sentence)
            char_set.insert(a);
        return int(char_set.size())==26;
        
    }
};


// another way to establish the set seen
class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Add every letter of 'sentence' to hash set 'seen'.
        unordered_set<char> seen(sentence.begin(), sentence.end());
        
        // If the size of 'seen' is 26, then 'sentence' is a pangram.
        return seen.size() == 26;
    }
};

// map every letter to a integer as the index (0~25)in a array
// letter - 'a'
// using that array to record the presence of a letter 
class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Array 'seen' of size 26.
        array<bool, 26> seen{};

        // For every letter 'currChar', we find its ASCII code, 
        // and update value at the mapped index as true.
        for (auto currChar : sentence)
            seen[currChar - 'a'] = true;
        
        // Once we finish iterating, check if 'seen' contains false.
        for (auto status : seen)
            if (!status)
                return false;
        return true;
    }
};

// using binary number to record whether or not a letter exists
class Solution {
public:
bool checkIfPangram(string sentence)
{
    int seen = 0;
    for(auto a : sentence)
    {
        int currBit = 1 << (a - 'a');
        seen |= currBit;
    }
    return seen == (1<<26) - 1;
}
};·