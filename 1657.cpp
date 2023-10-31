class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return false;
        vector<int> word1_freq(26);
        vector<int> word2_freq(26);
        unordered_set<char> word1_set;
        unordered_set<char> word2_set;
        for(int i=0;i<word1.size();i++)
        {
            char a = word1[i];
            char b = word2[i];
            word1_set.insert(a);
            word2_set.insert(b);
            word1_freq[a-'a'] ++;
            word2_freq[b-'a'] ++;
        }
        sort(word1_freq.begin(), word1_freq.end());
        sort(word2_freq.begin(), word2_freq.end());

        return (word1_freq==word2_freq)&&(word1_set==word2_set);
    }
};