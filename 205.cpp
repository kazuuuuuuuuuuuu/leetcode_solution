// using a map to record the mapping between s and t
// and second map for t to s
// check if there is any violation
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char, char> mapping;
        unordered_map<char, char> mapping2;
        for(int i=0;i<s.size();i++)
        {
            char a = s[i];
            char b = t[i];
            if(mapping.find(a)==mapping.end())
                mapping[a] = b;
            else
            {
                if(mapping[a]!=b)
                    return false;
            }
            a = t[i];
            b = s[i];
            if(mapping2.find(a)==mapping2.end())
                mapping2[a] = b;
            else
            {
                if(mapping2[a]!=b)
                    return false;
            }
        }
        return true;
    }
};

// transform the two string to a third party
bool isIsomorphic(string s, string t)
{
    if(s.size()!=t.size())
        return false;
    s = transformation(s);
    t = transformation(t);
    return s == t;

}

string transformation(string s)
{
    string ans;
    unordered_map<char, int> mapping;
    for(int i=0;i<s.size();i++)
    {
        char a = s[i];
        if(mapping.find(a)==mapping.end())
        {
            mapping[a] = i;
            ans +=  to_string(i) + ",";
        }
        else
        {
            ans +=  to_string(mapping[a]) + ",";
        }
    }
    return ans;
}

