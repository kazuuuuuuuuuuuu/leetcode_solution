// convert the two strings into a third party
// if their patterns are the same, the third parties are the same
// then return true, otherwise return false

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word;
        
        string s_trans;
        string pa_trans;
        
        int index = 0;
        
        unordered_map<string, int> s_mapping;
        unordered_map<char, int> pa_mapping;
        
        for(int i=0;i<=s.size();i++)
        {
            char a = s[i];
            if(a!=' '&&i!=s.size())
                word += a;
            else
            {
                if(s_mapping.find(word)==s_mapping.end())
                {
                    s_mapping[word] = index;
                    s_trans += s_mapping[word];
                    index ++;

                }
                else
                {
                    s_trans += s_mapping[word];
                }
                word = "";
            }
        }

        index = 0;
        for(int i=0;i<pattern.size();i++)
        {
            char a = pattern[i];
            if(pa_mapping.find(a)==pa_mapping.end())
            {
                pa_mapping[a] = index;
                pa_trans += pa_mapping[a];
                index ++;
            }
            else
            {
                pa_trans += pa_mapping[a];
            }
        }

        return s_trans==pa_trans;
    }
};