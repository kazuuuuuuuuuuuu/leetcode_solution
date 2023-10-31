// brute force 
// search from back to front to find the first element that appears twice 
class Solution {
public:
    char repeatedCharacter(string s) {
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            for (int j = 0; j < i; j++) {
                if (s[j] == c) {
                    return c;
                }
            }
        }       
        return ' ';
    }
};

// using set to check if the element we have seen before
class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> seen;
        for (char c: s) {
            if (seen.find(c) != seen.end()) {
                return c;
            }
            seen.insert(c);
        }
        
        return ' ';
    }
};