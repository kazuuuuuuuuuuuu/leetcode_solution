//keep a record of the frequency of each character in the strings
//append them into the answer string in the order specified by the string order
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> freq;     
        for(int i=0;i<s.size();i++)
        {
            char a = s[i];
            freq[a] ++;
        }

        string ans;
        for(int i=0;i<order.size();i++)
        {
            char a = order[i];
            ans.append(freq[a], a);
            freq.erase(a);
        }
        for(auto [a, freqency] : freq)
            ans.append(freqency, a);

        return ans;
    }
};