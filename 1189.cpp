class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> count;
        count['b'] = 0;
        count['a'] = 0;
        count['l'] = 0;
        count['o'] = 0;
        count['n'] = 0;
        for(char a : text)
        {
            switch(a)
            {
            case 'b':
            case 'a':
            case 'l':
            case 'o':
            case 'n':
                count[a] ++;
            }
        }

        count['l'] /= 2;
        count['o'] /= 2;
        int min = INT_MAX;
        for(auto[a, frequency] : count)
            min = min<frequency?min:frequency;
        return min;
    }
};


// method 2 using variable to record the frequency of each of five characters
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int bCount = 0, aCount = 0, lCount = 0, oCount = 0, nCount = 0;
        
        // Count the frequencey of all the five characters
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == 'b') {
                bCount++;
            } else if (text[i] == 'a') {
                aCount++;
            } else if (text[i] == 'l') {
                lCount++;
            } else if (text[i] == 'o') {
                oCount++;
            } else if (text[i] == 'n') {
                nCount++;
            }
        }
        
        // Find the potential of each character.
        // Except for 'l' and 'o' the potential is equal to the frequency.
        lCount = lCount / 2;
        oCount = oCount / 2;
        
        // Find the bottleneck.
        return min({bCount, aCount, lCount, oCount, nCount});
    }
};

//a generalized problem, the pattern is not specific

class Solution {
public:
    int findMaxNumberofPattern(string text, string pattern) {
        int n = text.length(), m = pattern.length(), answer = INT_MAX;
        int freqInText[26] = {0}, freqInPattern[26] = {0};
        
        // Frequency of characters in text.
        for (int i = 0; i < n; i++) {
            freqInText[text[i] - 'a']++;
        }
        // Frequency of characters in pattern.
        for (int i = 0; i < m; i++) {
            freqInPattern[pattern[i] - 'a']++;
        }
        
        // Compare the maximum string that can be produced
        // considering one character at a time.
        for (int i = 0; i < 26; i++) {
            // Do not divide by zero.
            if (freqInPattern[i]) {
                answer = min(answer, freqInText[i] / freqInPattern[i]);
            }
        }
        
        return answer;
    }
    
    int maxNumberOfBalloons(string text) {
        // Any string made up of lowercase English letters.
        string pattern = "balloon";
        return findMaxNumberofPattern(text, pattern);
    }
};