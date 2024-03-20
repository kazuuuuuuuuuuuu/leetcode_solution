class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash(26, 0);
        for(char a : s)
        {
            hash[a-'a'] ++;
        }
        for(char a : t)
        {
            hash[a-'a'] --;
        }        

        for(int i=0;i<26;i++)
        {
            if(hash[i]!=0)
                return false;
        }
        return true;
    }
};