class Solution {
public:
    string robotWithString(string s) 
    {
        // using a vector to keep the frequency of elements in string s
        vector<int> freq(26, 0);
        string t;
        string ans;
        for(char a : s)
        {
            freq[a-'a'] ++;
        }

        for(char a : s)
        {
            freq[a-'a'] --;
            t.push_back(a);
            // check the elements in the remaining string s, if there is not a character less than the current one 
            // the one  in the last position of t string, then output it to the ans string;
            // s中剩下的还有没有更小的， 没有就直接输出到答案里
            while(!t.empty()&&t.back()<=search_min(freq))
            {
                ans.push_back(t.back());
                t.pop_back();
            }
        }
        return ans;

    }

    char search_min(vector<int> &freq)
    {
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
                return 'a' + i;
        }
        // there is no character left
        // output the max 
        return 'a' + 26;
    }
};